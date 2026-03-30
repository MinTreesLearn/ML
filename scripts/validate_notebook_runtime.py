import json
from pathlib import Path


def main() -> int:
    nb_path = Path(r"d:/ML/Codeforces_RL_Recommender.ipynb")
    nb = json.loads(nb_path.read_text(encoding="utf-8"))
    ctx = {"__name__": "__main__"}

    for i, cell in enumerate(nb.get("cells", []), start=1):
        if cell.get("cell_type") != "code":
            continue
        source = "".join(cell.get("source", []))
        if not source.strip():
            continue
        try:
            exec(compile(source, f"cell_{i}", "exec"), ctx, ctx)
            print(f"[OK] Cell {i}")
        except Exception as exc:
            print(f"[ERR] Cell {i}: {type(exc).__name__}: {exc}")
            return 1

    print("[DONE] Notebook code cells executed successfully")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
