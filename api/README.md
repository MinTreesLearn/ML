# FastAPI Service - Codeforces RL Recommender

Dich vu nay dong goi logic notebook thanh API de gan vao backend.

## Chay nhanh
```bash
d:/ML/.venv/Scripts/python.exe -m uvicorn api.main:app --host 0.0.0.0 --port 8000 --reload
```

## Bien moi truong startup train
- RL_STARTUP_EPISODES (mac dinh: 30)
- RL_STARTUP_USERS_PER_EPISODE (mac dinh: 5)
- RL_STARTUP_MAX_STEPS (mac dinh: 20)

Vi du:
```bash
set RL_STARTUP_EPISODES=100
set RL_STARTUP_USERS_PER_EPISODE=5
set RL_STARTUP_MAX_STEPS=20
d:/ML/.venv/Scripts/python.exe -m uvicorn api.main:app --host 0.0.0.0 --port 8000
```

## Endpoints
- GET /health
- GET /metrics
- POST /train
- POST /recommend
- POST /progress

Swagger:
- http://localhost:8000/docs

## Payload mau
### POST /train
```json
{
  "episodes": 100,
  "users_per_episode": 5,
  "max_steps_per_episode": 20
}
```

### POST /recommend
```json
{
  "user_id": 12345,
  "rating": 1400,
  "accuracy": 0.6,
  "streak": 2,
  "num_recommendations": 5
}
```

### POST /progress
```json
{
  "user_id": 2026,
  "rating": 1000,
  "accuracy": 0.35,
  "streak": 0,
  "num_recommendations": 5
}
```
