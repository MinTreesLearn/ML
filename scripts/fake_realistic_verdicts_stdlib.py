import argparse
import csv
import hashlib
import random
from collections import Counter
from pathlib import Path


VERDICTS = [
    "OK",
    "WRONG_ANSWER",
    "TIME_LIMIT_EXCEEDED",
    "RUNTIME_ERROR",
    "COMPILATION_ERROR",
    "MEMORY_LIMIT_EXCEEDED",
]


def stable_int(value: str) -> int:
    h = hashlib.sha256(value.encode("utf-8")).hexdigest()
    return int(h[:16], 16)


def build_handle_pool(n_buckets: int, seed: int) -> list[str]:
    rng = random.Random(seed + 2026)
    prefixes = [
        "code", "cf", "algo", "byte", "graph", "dp", "omega", "nova", "zen", "zero",
        "quant", "pixel", "void", "storm", "delta", "prime", "kira", "atlas", "vortex", "ninja",
    ]
    suffixes = [
        "coder", "hunter", "master", "_x", "_pro", "_01", "_dev", "fox", "wolf", "_cf",
        "_up", "light", "forge", "edge", "nova", "wave", "spark", "_bt", "_ac", "",
    ]

    handles: list[str] = []
    used = set()
    while len(handles) < n_buckets:
        p = rng.choice(prefixes)
        s = rng.choice(suffixes)
        num_part = ""
        if rng.random() < 0.72:
            num_part = str(rng.randint(1, 9999))
        handle = f"{p}{s}{num_part}"

        # Add occasional mixed case to resemble real CF handles.
        if rng.random() < 0.18 and len(handle) > 4:
            i = rng.randint(1, min(4, len(handle) - 1))
            handle = handle[:i] + handle[i].upper() + handle[i + 1 :]

        if 3 <= len(handle) <= 24 and handle not in used:
            used.add(handle)
            handles.append(handle)

    return handles


def clamp(x: float, lo: float, hi: float) -> float:
    return max(lo, min(hi, x))


def infer_problem_difficulty(problem_id: str) -> float:
    if not problem_id:
        return 0.5
    p = problem_id.upper()
    letter = p[0] if p else "C"
    if letter in "AB":
        return 0.25
    if letter in "CD":
        return 0.5
    if letter in "EF":
        return 0.72
    return 0.85


def infer_language_factor(language: str) -> float:
    lang = (language or "").lower()
    if lang in {"cpp", "cc", "cxx"}:
        return 1.0
    if lang in {"java", "kt", "kotlin"}:
        return 0.93
    if lang in {"py", "python", "python3"}:
        return 0.84
    return 0.9


def generate_verdict(row: dict, rng: random.Random) -> tuple[str, int]:
    pid = row.get("problem_id", "")
    lang = row.get("language", "")
    sid = row.get("submission_id", "")

    d = infer_problem_difficulty(pid)
    lf = infer_language_factor(lang)

    # Base AC probability by difficulty + language factor
    p_ok = clamp(0.88 - 0.55 * d, 0.18, 0.86) * lf

    # Add stable per-submission noise for repeatable realism
    noise = (stable_int(str(sid)) % 1000) / 1000.0
    p_ok = clamp(p_ok + (noise - 0.5) * 0.12, 0.08, 0.92)

    # Remaining probability split by common CF-style errors
    rest = 1.0 - p_ok
    p_wa = rest * (0.50 if d < 0.65 else 0.42)
    p_tle = rest * (0.22 if lang.lower() in {"py", "python", "python3"} else 0.16)
    p_re = rest * 0.13
    p_ce = rest * (0.06 if lang.lower() in {"cpp", "java", "kt", "kotlin"} else 0.03)
    p_mle = max(0.0, rest - (p_wa + p_tle + p_re + p_ce))

    probs = [p_ok, p_wa, p_tle, p_re, p_ce, p_mle]
    # Normalize for numeric safety
    s = sum(probs)
    probs = [p / s for p in probs]

    r = rng.random()
    acc = 0.0
    for verdict, p in zip(VERDICTS, probs):
        acc += p
        if r <= acc:
            return verdict, 1 if verdict == "OK" else 0
    return "WRONG_ANSWER", 0


def assign_user_handle(row: dict, handle_pool: list[str]) -> str:
    # Deterministic clustering so each synthetic user has enough history
    sid = str(row.get("submission_id", ""))
    cid = str(row.get("contest_id", ""))
    key = f"{cid}:{sid}"
    bucket = stable_int(key) % max(1, len(handle_pool))
    return handle_pool[bucket]


def assign_creation_time(row: dict) -> str:
    existing = str(row.get("creation_time", "") or "").strip()
    if existing:
        return existing
    sid = str(row.get("submission_id", "0"))
    try:
        n = int("".join(ch for ch in sid if ch.isdigit()) or "0")
    except ValueError:
        n = stable_int(sid)
    # Map to realistic unix epoch range 2017-2024
    start = 1483228800
    span = 252460800
    return str(start + (n % span))


def main() -> int:
    parser = argparse.ArgumentParser(description="Create realistic synthetic verdicts from UNKNOWN rows.")
    parser.add_argument("--input-csv", required=True)
    parser.add_argument("--output-csv", required=True)
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--overwrite-all", action="store_true")
    args = parser.parse_args()

    in_path = Path(args.input_csv)
    out_path = Path(args.output_csv)

    if not in_path.exists():
        raise FileNotFoundError(f"Input CSV not found: {in_path}")

    rng = random.Random(args.seed)
    with in_path.open("r", encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        rows = list(reader)
        fieldnames = list(reader.fieldnames or [])

    for required in ["verdict", "is_accepted", "creation_time", "user_handle"]:
        if required not in fieldnames:
            fieldnames.append(required)

    updated = 0
    # Keep user pool compact enough so each user has sequence history.
    n_buckets = max(8, min(40, len(rows) // 12))
    handle_pool = build_handle_pool(n_buckets, args.seed)
    verdict_counter = Counter()

    for row in rows:
        current_verdict = str(row.get("verdict", "") or "").strip().upper()
        should_update = args.overwrite_all or current_verdict in {"", "UNKNOWN", "NAN", "NONE"}

        if should_update:
            verdict, is_acc = generate_verdict(row, rng)
            row["verdict"] = verdict
            row["is_accepted"] = str(is_acc)
            updated += 1

        row["creation_time"] = assign_creation_time(row)
        row["user_handle"] = assign_user_handle(row, handle_pool)

        verdict_counter[str(row.get("verdict", "UNKNOWN"))] += 1

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    print(f"Rows: {len(rows)}")
    print(f"Updated rows: {updated}")
    print("Verdict distribution:")
    for k, v in verdict_counter.most_common(10):
        print(f"  {k}: {v}")
    print(f"User buckets: {n_buckets}")
    print("Sample handles:")
    for h in handle_pool[:10]:
        print(f"  {h}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
