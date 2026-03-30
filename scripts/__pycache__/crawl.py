import argparse
import json
import time
from pathlib import Path
from typing import Dict, List, Set, Tuple
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen

import pandas as pd


API_URL = "https://codeforces.com/api/contest.status"


def fetch_contest_status_page(contest_id: int, start_from: int, count: int, timeout: int = 30) -> List[dict]:
    url = f"{API_URL}?contestId={contest_id}&from={start_from}&count={count}"
    req = Request(url, headers={"User-Agent": "Mozilla/5.0"})
    with urlopen(req, timeout=timeout) as resp:
        payload = json.loads(resp.read().decode("utf-8"))
    if payload.get("status") != "OK":
        raise RuntimeError(f"API error for contest {contest_id}: {payload}")
    return payload.get("result", [])


def build_local_index(submissions_root: Path, max_local_rows: int = 0) -> pd.DataFrame:
    rows: List[dict] = []

    for contest_dir in submissions_root.iterdir():
        if not contest_dir.is_dir():
            continue

        contest_name = contest_dir.name
        if not contest_name.isdigit():
            continue

        contest_id = int(contest_name)

        for problem_dir in contest_dir.iterdir():
            if not problem_dir.is_dir():
                continue

            problem_id = problem_dir.name

            for submission_file in problem_dir.iterdir():
                if not submission_file.is_file():
                    continue
                if submission_file.suffix not in {".py", ".java", ".cpp"}:
                    continue

                rows.append(
                    {
                        "contest_id": contest_id,
                        "problem_id": problem_id,
                        "submission_id": str(submission_file.stem),
                        "language": submission_file.suffix[1:],
                    }
                )

                if max_local_rows > 0 and len(rows) >= max_local_rows:
                    break

            if max_local_rows > 0 and len(rows) >= max_local_rows:
                break

        if max_local_rows > 0 and len(rows) >= max_local_rows:
            break

    if not rows:
        return pd.DataFrame(columns=["contest_id", "problem_id", "submission_id", "language"])

    return (
        pd.DataFrame(rows)
        .drop_duplicates(subset=["contest_id", "problem_id", "submission_id"])
        .reset_index(drop=True)
    )


def enrich_verdicts(
    local_index_df: pd.DataFrame,
    max_contests: int,
    page_size: int,
    max_pages_per_contest: int,
    sleep_seconds: float,
) -> Tuple[pd.DataFrame, List[Tuple[int, str]]]:
    if local_index_df.empty:
        return pd.DataFrame(), []

    contest_ids = sorted(local_index_df["contest_id"].dropna().astype(int).unique().tolist())
    selected_contests = contest_ids[:max_contests] if max_contests > 0 else contest_ids

    target_ids_by_contest: Dict[int, Set[str]] = {}
    for contest_id, group in local_index_df.groupby("contest_id"):
        target_ids_by_contest[int(contest_id)] = set(group["submission_id"].astype(str).tolist())

    api_rows: List[dict] = []
    failed_contests: List[Tuple[int, str]] = []

    for i, contest_id in enumerate(selected_contests, 1):
        target_ids = target_ids_by_contest.get(contest_id, set())
        if not target_ids:
            continue

        found_ids: Set[str] = set()

        try:
            for page in range(max_pages_per_contest):
                start_from = page * page_size + 1
                rows = fetch_contest_status_page(contest_id, start_from=start_from, count=page_size)
                if not rows:
                    break

                for row in rows:
                    sid_raw = row.get("id")
                    sid = str(sid_raw) if sid_raw is not None else None
                    if sid not in target_ids:
                        continue

                    problem = row.get("problem", {}) or {}
                    author = row.get("author", {}) or {}
                    members = author.get("members", []) or []
                    handle = members[0].get("handle") if members and isinstance(members[0], dict) else None

                    verdict = row.get("verdict")
                    api_rows.append(
                        {
                            "contest_id": contest_id,
                            "submission_id": sid,
                            "problem_id": str(problem.get("index")) if problem.get("index") is not None else None,
                            "verdict": verdict,
                            "is_accepted": int(verdict == "OK") if verdict is not None else 0,
                            "creation_time": row.get("creationTimeSeconds"),
                            "user_handle": handle,
                        }
                    )
                    found_ids.add(sid)

                if len(found_ids) == len(target_ids):
                    break
                if len(rows) < page_size:
                    break

                if sleep_seconds > 0:
                    time.sleep(sleep_seconds)

            print(
                f"Processed {i}/{len(selected_contests)} contests | "
                f"matched rows: {len(api_rows)}"
            )

        except (URLError, HTTPError, RuntimeError, TimeoutError) as exc:
            failed_contests.append((contest_id, str(exc)))

    if not api_rows:
        return pd.DataFrame(), failed_contests

    api_df = (
        pd.DataFrame(api_rows)
        .drop_duplicates(subset=["contest_id", "problem_id", "submission_id"])
        .reset_index(drop=True)
    )
    return api_df, failed_contests


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Fetch real Codeforces verdicts (contest.status) and save canonical submissions CSV."
    )
    parser.add_argument(
        "--submissions-root",
        type=Path,
        default=Path(r"d:\ML\Codeforces Submissions"),
        help="Root folder containing local Codeforces submissions.",
    )
    parser.add_argument(
        "--output-csv",
        type=Path,
        default=Path(r"d:\ML\generated\submissions_with_verdict.csv"),
        help="Output CSV path for canonical submissions table.",
    )
    parser.add_argument("--max-local-rows", type=int, default=0, help="Limit local indexed rows (0 = no limit).")
    parser.add_argument("--max-contests", type=int, default=20, help="Max contests to fetch from API (0 = all).")
    parser.add_argument("--page-size", type=int, default=5000, help="API page size for contest.status.")
    parser.add_argument(
        "--max-pages-per-contest",
        type=int,
        default=40,
        help="Max pages to scan per contest.",
    )
    parser.add_argument("--sleep", type=float, default=0.2, help="Delay seconds between API page requests.")

    args = parser.parse_args()

    if not args.submissions_root.exists():
        raise FileNotFoundError(f"Submissions root not found: {args.submissions_root}")

    print("Building local submissions index...")
    local_df = build_local_index(args.submissions_root, max_local_rows=args.max_local_rows)
    print(f"Local index rows: {len(local_df)}")

    if local_df.empty:
        print("No local submissions found. Exiting.")
        return

    print("Fetching real verdicts from Codeforces API...")
    api_df, failed = enrich_verdicts(
        local_df,
        max_contests=args.max_contests,
        page_size=args.page_size,
        max_pages_per_contest=args.max_pages_per_contest,
        sleep_seconds=args.sleep,
    )

    if not api_df.empty:
        merged = local_df.merge(
            api_df,
            on=["contest_id", "problem_id", "submission_id"],
            how="left",
        )
    else:
        merged = local_df.copy()

    merged["verdict"] = merged.get("verdict", pd.Series([None] * len(merged))).fillna("UNKNOWN")
    merged["is_accepted"] = merged.get("is_accepted", pd.Series([0] * len(merged))).fillna(0).astype(int)

    canonical_cols = [
        "contest_id",
        "problem_id",
        "submission_id",
        "language",
        "verdict",
        "is_accepted",
        "creation_time",
        "user_handle",
    ]

    for col in canonical_cols:
        if col not in merged.columns:
            merged[col] = None

    out_df = merged[canonical_cols].copy()
    args.output_csv.parent.mkdir(parents=True, exist_ok=True)
    out_df.to_csv(args.output_csv, index=False, encoding="utf-8")

    print(f"Saved: {args.output_csv}")
    print(f"Rows: {len(out_df)}")
    print("Verdict distribution (top 10):")
    print(out_df["verdict"].value_counts().head(10))

    if failed:
        print(f"Failed contests: {len(failed)}")
        print("Failed sample:", failed[:3])


if __name__ == "__main__":
    main()
