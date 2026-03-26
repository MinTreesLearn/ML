import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m, k = map(int, input().split())
ans = "YES" if k <= 4 * n * m - 2 * n - 2 * m else "NO"
print(ans)
if ans == "NO":
    exit()
ans = []
if n == 1:
    f = min(m - 1, k)
    k -= f
    ans.append(" ".join((str(f), "R")))
    if k:
        f = min(m - 1, k)
        k -= f
        ans.append(" ".join((str(f), "L")))
elif m == 1:
    f = min(n - 1, k)
    k -= f
    ans.append(" ".join((str(f), "D")))
    if k:
        f = min(n - 1, k)
        k -= f
        ans.append(" ".join((str(f), "U")))
else:
    for _ in range(n - 1):
        if not k:
            break
        f = min(m - 1, k)
        k -= f
        ans.append(" ".join((str(f), "R")))
        if not k:
            break
        f = min(m - 1, k)
        k -= f
        ans.append(" ".join((str(f), "L")))
        if not k:
            break
        f = 1
        k -= f
        ans.append(" ".join((str(f), "D")))
    for _ in range(m - 1):
        if not k:
            break
        f = 1
        k -= f
        ans.append(" ".join((str(f), "R")))
        if not k:
            break
        f = min(n - 1, k)
        k -= f
        ans.append(" ".join((str(f), "U")))
        if not k:
            break
        f = min(n - 1, k)
        k -= f
        ans.append(" ".join((str(f), "D")))
    if k:
        f = min(m - 1, k)
        k -= f
        ans.append(" ".join((str(f), "L")))
    if k:
        f = min(n - 1, k)
        k -= f
        ans.append(" ".join((str(f), "U")))
a = len(ans)
print(a)
sys.stdout.write("\n".join(ans))