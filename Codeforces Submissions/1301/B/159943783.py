import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
inf = pow(10, 9) + 1
for _ in range(t):
    n = int(input())
    a = [0] + list(map(int, input().split())) + [0]
    ma, mi = -inf, inf
    for i in range(1, n + 1):
        if not a[i] == -1 and min(a[i - 1], a[i + 1]) == -1:
            ma = max(ma, a[i])
            mi = min(mi, a[i])
    m0 = 0
    for i in range(1, n):
        if min(a[i], a[i + 1]) > -1:
            m0 = max(m0, abs(a[i] - a[i + 1]))
    m, k = 0, 0
    if mi <= ma:
        m = max((ma - mi + 1) // 2, m0)
        k = mi + (ma - mi + 1) // 2
    ans.append(" ".join(map(str, (m, k))))
sys.stdout.write("\n".join(ans))