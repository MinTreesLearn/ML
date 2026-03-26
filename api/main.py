from __future__ import annotations

import os
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Tuple

import numpy as np
import pandas as pd
from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel, Field
from scipy.special import expit

BASE_DIR = Path(r"d:/ML")
PROBLEMS_CSV = BASE_DIR / "Codeforces Problems" / "data.csv"
SUBMISSIONS_DIR = BASE_DIR / "Codeforces Submissions"


class RecommendRequest(BaseModel):
    user_id: int = Field(default=9999)
    rating: float = Field(default=1200, ge=600, le=4000)
    accuracy: float = Field(default=0.5, ge=0.0, le=1.0)
    streak: int = Field(default=0, ge=0, le=1000)
    num_recommendations: int = Field(default=5, ge=1, le=20)


class TrainRequest(BaseModel):
    episodes: int = Field(default=100, ge=1, le=2000)
    users_per_episode: int = Field(default=5, ge=1, le=200)
    max_steps_per_episode: int = Field(default=20, ge=1, le=200)


class ProgrammingExerciseEnv:
    ACTION_DIFFICULTY = {0: (800, 1200), 1: (1200, 1800), 2: (1800, 3500)}

    def __init__(
        self,
        problem_ratings: Dict[str, int],
        num_rating_buckets: int = 5,
        num_accuracy_buckets: int = 3,
        num_streak_buckets: int = 4,
    ):
        self.problem_ratings = problem_ratings
        self.num_rating_buckets = num_rating_buckets
        self.num_accuracy_buckets = num_accuracy_buckets
        self.num_streak_buckets = num_streak_buckets
        self.rating_range = (600, 3500)

        self.problems_by_difficulty: Dict[int, List[str]] = {0: [], 1: [], 2: []}
        for prob_id, rating in self.problem_ratings.items():
            if 800 <= rating < 1200:
                self.problems_by_difficulty[0].append(prob_id)
            elif 1200 <= rating < 1800:
                self.problems_by_difficulty[1].append(prob_id)
            else:
                self.problems_by_difficulty[2].append(prob_id)

    def discretize_state(self, rating: float, accuracy: float, streak: int) -> Tuple[int, int, int]:
        rating_bucket = int(
            np.clip(
                (rating - self.rating_range[0])
                / (self.rating_range[1] - self.rating_range[0])
                * (self.num_rating_buckets - 1),
                0,
                self.num_rating_buckets - 1,
            )
        )
        accuracy_bucket = int(np.clip(accuracy * (self.num_accuracy_buckets - 1), 0, self.num_accuracy_buckets - 1))
        streak_bucket = min(int(streak), self.num_streak_buckets - 1)
        return (rating_bucket, accuracy_bucket, streak_bucket)

    def get_success_probability(self, user_rating: float, problem_rating: float) -> float:
        diff = user_rating - problem_rating
        return float(expit(0.002 * diff))

    def take_action(self, action: int, user_state: Dict[str, float]):
        available = self.problems_by_difficulty.get(action, [])
        if not available:
            available = list(self.problem_ratings.keys())

        problem_id = str(np.random.choice(available))
        problem_rating = float(self.problem_ratings[problem_id])

        p_success = self.get_success_probability(user_state["rating"], problem_rating)
        is_success = bool(np.random.random() < p_success)
        reward = (1 + action) if is_success else -1

        old_accuracy = float(user_state["accuracy"])
        old_streak = int(user_state["streak"])

        if is_success:
            new_accuracy = (old_accuracy * 9 + 1) / 10
            new_streak = old_streak + 1
            delta_rating = 0.5
        else:
            new_accuracy = (old_accuracy * 9) / 10
            new_streak = 0
            delta_rating = -0.2

        new_state = {
            "rating": float(user_state["rating"] + delta_rating),
            "accuracy": float(new_accuracy),
            "streak": int(new_streak),
            "user_id": int(user_state["user_id"]),
        }

        return reward, new_state, is_success, problem_id, problem_rating


class QLearningAgent:
    def __init__(self, env: ProgrammingExerciseEnv, alpha: float = 0.1, gamma: float = 0.95, epsilon: float = 1.0):
        self.env = env
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.epsilon_min = 0.01
        self.epsilon_decay = 0.995
        self.q_table = defaultdict(lambda: np.zeros(3, dtype=float))

    def select_action(self, state, training: bool = True) -> int:
        if training and np.random.random() < self.epsilon:
            return int(np.random.randint(0, 3))
        return int(np.argmax(self.q_table[state]))

    def update_q(self, state, action, reward, next_state):
        q_current = self.q_table[state][action]
        q_next = float(np.max(self.q_table[next_state]))
        td_error = reward + self.gamma * q_next - q_current
        self.q_table[state][action] = q_current + self.alpha * td_error

    def train_episode(self, user_state: Dict[str, float], max_steps: int = 20, collect_trace: bool = False):
        current = user_state.copy()
        state = self.env.discretize_state(current["rating"], current["accuracy"], current["streak"])

        total_reward = 0.0
        success_count = 0
        trace = {
            "rating_history": [],
            "accuracy_history": [],
            "difficulty_history": [],
            "problem_rating_history": [],
            "reward_history": [],
            "result_history": [],
        }

        for _ in range(max_steps):
            action = self.select_action(state, training=True)
            reward, nxt, ok, _, problem_rating = self.env.take_action(action, current)
            next_state = self.env.discretize_state(nxt["rating"], nxt["accuracy"], nxt["streak"])

            self.update_q(state, action, reward, next_state)

            total_reward += reward
            success_count += int(ok)

            if collect_trace:
                trace["rating_history"].append(float(nxt["rating"]))
                trace["accuracy_history"].append(float(nxt["accuracy"]))
                trace["difficulty_history"].append(int(action))
                trace["problem_rating_history"].append(float(problem_rating))
                trace["reward_history"].append(float(reward))
                trace["result_history"].append("AC" if ok else "WA")

            state = next_state
            current = nxt

        if self.epsilon > self.epsilon_min:
            self.epsilon *= self.epsilon_decay

        return total_reward, success_count, trace

    def predict_action(self, state) -> int:
        return int(np.argmax(self.q_table[state]))


class RLService:
    def __init__(self):
        self.data_cleaned: pd.DataFrame | None = None
        self.user_states: Dict[int, Dict[str, float]] = {}
        self.problem_ratings: Dict[str, int] = {}
        self.env: ProgrammingExerciseEnv | None = None
        self.agent: QLearningAgent | None = None
        self.training_traces: List[Dict[str, List[float]]] = []
        self.q_learning_rewards: List[float] = []
        self.q_learning_accuracies: List[float] = []

    def _load_problem_data(self) -> pd.DataFrame:
        if not PROBLEMS_CSV.exists():
            raise FileNotFoundError(f"Problems file not found: {PROBLEMS_CSV}")
        return pd.read_csv(PROBLEMS_CSV)

    def _build_submissions_data(self, problems_df: pd.DataFrame) -> pd.DataFrame:
        submissions_data = []
        if SUBMISSIONS_DIR.exists():
            for contest_dir in SUBMISSIONS_DIR.iterdir():
                if not contest_dir.is_dir():
                    continue
                contest_id = contest_dir.name
                for problem_dir in contest_dir.iterdir():
                    if not problem_dir.is_dir():
                        continue
                    for submission_file in problem_dir.iterdir():
                        if submission_file.is_file() and submission_file.suffix in [".py", ".java", ".cpp"]:
                            submissions_data.append(
                                {
                                    "contest_id": int(contest_id),
                                    "problem_id": problem_dir.name,
                                    "submission_id": submission_file.stem,
                                    "verdict": "AC",
                                    "language": submission_file.suffix[1:],
                                }
                            )
                if len(submissions_data) >= 1000:
                    break

        np.random.seed(42)
        num_users = 100
        num_submissions_per_user = 50

        if "contest" in problems_df.columns and "problem_name" in problems_df.columns:
            unique_problems = problems_df["contest"].astype(str) + "_" + problems_df["problem_name"].astype(str).str[:1]
            unique_problems = unique_problems.unique()[:200]
        else:
            unique_problems = np.array([f"P{i}" for i in range(100)])

        synthetic = []
        for user_id in range(num_users):
            user_rating = int(800 + np.random.randint(-200, 2000))
            for _ in range(num_submissions_per_user):
                synthetic.append(
                    {
                        "user_id": user_id,
                        "user_rating": user_rating,
                        "problem_id": str(np.random.choice(unique_problems)),
                        "verdict": str(np.random.choice(["AC", "WA", "TLE", "RE"], p=[0.6, 0.2, 0.1, 0.1])),
                        "timestamp": int(np.random.randint(1000000, 2000000)),
                    }
                )

        return pd.DataFrame(synthetic)

    def _preprocess(self, problems_df: pd.DataFrame, submissions_df: pd.DataFrame):
        problem_ratings: Dict[str, int] = {}

        if "contest" in problems_df.columns and "problem_name" in problems_df.columns and "problem_tags" in problems_df.columns:
            for _, row in problems_df.iterrows():
                try:
                    prob_id = str(row["contest"]) + "_" + str(row["problem_name"]).split()[0]
                    tags = str(row["problem_tags"])
                    rating = int(tags.split("*")[1].split()[0]) if "*" in tags else 1000
                    problem_ratings[prob_id] = rating
                except Exception:
                    continue

        if not problem_ratings:
            for problem in submissions_df["problem_id"].unique():
                problem_ratings[str(problem)] = int(np.random.randint(800, 3000, step=100))

        min_submissions = 10
        valid_users = submissions_df.groupby("user_id").size()
        valid_users = valid_users[valid_users >= min_submissions].index.tolist()

        data_cleaned = submissions_df[submissions_df["user_id"].isin(valid_users)].copy()
        data_cleaned["problem_rating"] = data_cleaned["problem_id"].map(lambda x: problem_ratings.get(str(x), 1000))
        data_cleaned["is_accepted"] = (data_cleaned["verdict"] == "AC").astype(int)
        data_cleaned = data_cleaned.sort_values("timestamp").reset_index(drop=True)

        self.problem_ratings = problem_ratings
        self.data_cleaned = data_cleaned

    def _calculate_user_features(self, user_id: int, window_size: int = 10) -> Dict[str, float]:
        assert self.data_cleaned is not None
        user_submissions = self.data_cleaned[self.data_cleaned["user_id"] == user_id].tail(window_size)

        if len(user_submissions) == 0:
            return {"accuracy": 0.5, "streak": 0, "rating": 1000.0, "user_id": user_id}

        accuracy = float(user_submissions["is_accepted"].mean())
        verdicts = user_submissions["is_accepted"].values

        streak = 0
        for v in reversed(verdicts):
            if v == 1:
                streak += 1
            else:
                break

        rating = float(user_submissions["user_rating"].iloc[-1])
        return {"accuracy": accuracy, "streak": int(streak), "rating": rating, "user_id": int(user_id)}

    def initialize(self):
        problems_df = self._load_problem_data()
        submissions_df = self._build_submissions_data(problems_df)
        self._preprocess(problems_df, submissions_df)

        assert self.data_cleaned is not None
        self.user_states = {
            int(uid): self._calculate_user_features(int(uid)) for uid in self.data_cleaned["user_id"].unique()
        }

        self.env = ProgrammingExerciseEnv(self.problem_ratings)
        self.agent = QLearningAgent(self.env)

    def train(self, episodes: int = 100, users_per_episode: int = 5, max_steps_per_episode: int = 20):
        if self.env is None or self.agent is None or not self.user_states:
            self.initialize()

        self.training_traces = []
        self.q_learning_rewards = []
        self.q_learning_accuracies = []

        user_ids = list(self.user_states.keys())
        for episode in range(episodes):
            episode_total_reward = 0.0
            episode_total_success = 0
            episode_total_steps = 0

            sampled_users = np.random.choice(user_ids, size=min(users_per_episode, len(user_ids)), replace=True)
            episode_trace = {
                "episode": episode + 1,
                "rating_history": [],
                "accuracy_history": [],
                "difficulty_history": [],
                "problem_rating_history": [],
                "reward_history": [],
                "result_history": [],
            }

            for user_id in sampled_users:
                reward, success_count, trace = self.agent.train_episode(
                    user_state=self.user_states[int(user_id)],
                    max_steps=max_steps_per_episode,
                    collect_trace=True,
                )
                episode_total_reward += reward
                episode_total_success += success_count
                episode_total_steps += max_steps_per_episode

                for key in [
                    "rating_history",
                    "accuracy_history",
                    "difficulty_history",
                    "problem_rating_history",
                    "reward_history",
                    "result_history",
                ]:
                    episode_trace[key].extend(trace[key])

            self.q_learning_rewards.append(float(episode_total_reward / users_per_episode))
            self.q_learning_accuracies.append(float(episode_total_success / episode_total_steps if episode_total_steps else 0.0))
            self.training_traces.append(episode_trace)

    def recommend(self, user_state: Dict[str, float], num_recommendations: int = 5):
        if self.env is None or self.agent is None:
            raise RuntimeError("Service is not initialized")

        state = self.env.discretize_state(user_state["rating"], user_state["accuracy"], int(user_state["streak"]))
        q_values = self.agent.q_table[state].copy()
        best_action = int(np.argmax(q_values))

        difficulty_names = {0: "Easy", 1: "Medium", 2: "Hard"}
        reasons = [f"User đang ở level {int(user_state['rating'])} nên chọn bài {difficulty_names[best_action]}. "]

        if user_state["accuracy"] < 0.45 and best_action > 0:
            best_action -= 1
            reasons.append("Accuracy thấp nên giảm độ khó để củng cố nền tảng.")

        if user_state["streak"] >= 3 and user_state["accuracy"] >= 0.65 and best_action < 2:
            best_action += 1
            reasons.append("Streak cao nên tăng độ khó để thúc đẩy tiến bộ.")

        candidates = self.env.problems_by_difficulty.get(best_action, [])
        if not candidates:
            candidates = list(self.problem_ratings.keys())

        n = min(num_recommendations, len(candidates))
        selected = np.random.choice(candidates, size=n, replace=False)
        problems = [
            {
                "problem_id": str(pid),
                "rating": int(self.problem_ratings[str(pid)]),
                "difficulty": difficulty_names[best_action],
                "difficulty_level": best_action,
            }
            for pid in selected
        ]

        return {
            "user_id": int(user_state["user_id"]),
            "user_rating": float(user_state["rating"]),
            "user_accuracy": float(user_state["accuracy"]),
            "recommended_difficulty": difficulty_names[best_action],
            "recommended_difficulty_level": best_action,
            "q_values": {
                "Easy": float(q_values[0]),
                "Medium": float(q_values[1]),
                "Hard": float(q_values[2]),
            },
            "reason": " ".join(reasons),
            "problems": problems,
        }

    def progress(self, user_state: Dict[str, float], steps: int = 80):
        if self.env is None or self.agent is None:
            raise RuntimeError("Service is not initialized")

        current = user_state.copy()
        trace = {
            "step": [],
            "rating_history": [],
            "accuracy_history": [],
            "difficulty_history": [],
            "problem_rating_history": [],
            "reward_history": [],
            "result_history": [],
        }

        for step in range(1, steps + 1):
            state = self.env.discretize_state(current["rating"], current["accuracy"], int(current["streak"]))
            action = self.agent.predict_action(state)
            reward, nxt, ok, _, problem_rating = self.env.take_action(action, current)

            trace["step"].append(step)
            trace["rating_history"].append(float(nxt["rating"]))
            trace["accuracy_history"].append(float(nxt["accuracy"]))
            trace["difficulty_history"].append(int(action))
            trace["problem_rating_history"].append(float(problem_rating))
            trace["reward_history"].append(float(reward))
            trace["result_history"].append("AC" if ok else "WA")
            current = nxt

        return trace


service = RLService()
app = FastAPI(title="Codeforces RL Recommender API", version="1.0.0")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


@app.on_event("startup")
def startup_event():
    episodes = int(os.getenv("RL_STARTUP_EPISODES", "30"))
    users_per_episode = int(os.getenv("RL_STARTUP_USERS_PER_EPISODE", "5"))
    max_steps = int(os.getenv("RL_STARTUP_MAX_STEPS", "20"))

    service.initialize()
    service.train(episodes=episodes, users_per_episode=users_per_episode, max_steps_per_episode=max_steps)


@app.get("/health")
def health():
    return {
        "status": "ok",
        "trained": len(service.q_learning_rewards) > 0,
        "episodes": len(service.q_learning_rewards),
        "q_table_states": len(service.agent.q_table) if service.agent else 0,
    }


@app.get("/metrics")
def metrics():
    if not service.q_learning_rewards:
        return {"trained": False}

    return {
        "trained": True,
        "episodes": len(service.q_learning_rewards),
        "final_avg_reward": service.q_learning_rewards[-1],
        "final_success_rate": service.q_learning_accuracies[-1],
        "avg_reward_last_50": float(np.mean(service.q_learning_rewards[-50:])),
        "avg_accuracy_last_50": float(np.mean(service.q_learning_accuracies[-50:])),
        "q_table_states": len(service.agent.q_table) if service.agent else 0,
    }


@app.post("/train")
def train(request: TrainRequest):
    service.train(
        episodes=request.episodes,
        users_per_episode=request.users_per_episode,
        max_steps_per_episode=request.max_steps_per_episode,
    )
    return {
        "message": "Training completed",
        "episodes": len(service.q_learning_rewards),
        "final_avg_reward": service.q_learning_rewards[-1],
        "final_success_rate": service.q_learning_accuracies[-1],
        "q_table_states": len(service.agent.q_table) if service.agent else 0,
    }


@app.post("/recommend")
def recommend(request: RecommendRequest):
    if service.agent is None:
        raise HTTPException(status_code=503, detail="Model is not ready")

    payload = {
        "user_id": request.user_id,
        "rating": request.rating,
        "accuracy": request.accuracy,
        "streak": request.streak,
    }
    return service.recommend(payload, num_recommendations=request.num_recommendations)


@app.post("/progress")
def progress(request: RecommendRequest):
    if service.agent is None:
        raise HTTPException(status_code=503, detail="Model is not ready")

    payload = {
        "user_id": request.user_id,
        "rating": request.rating,
        "accuracy": request.accuracy,
        "streak": request.streak,
    }
    return service.progress(payload, steps=80)
