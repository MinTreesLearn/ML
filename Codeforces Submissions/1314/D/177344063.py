import random
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
pow2 = [1]
for _ in range(30):
    pow2.append(2 * pow2[-1])
inf = pow(10, 9) + 1
ans = inf
for _ in range(5000):
    u = [random.randint(0, pow(2, 30) - 1) for _ in range(3)]
    x = [[] for _ in range(2)]
    for i in range(n):
        x[min(1, u[i // 30] & pow2[i % 30])].append(i)
    d = [[] for _ in range(n)]
    x1, x2 = x
    for _ in range(2):
        for i in x1:
            ai = a[i]
            for j in x2:
                d[i].append((j, ai[j]))
        x1, x2 = x2, x1
    dp0 = [inf] * n
    dp0[0] = 0
    for _ in range(k):
        dp = [inf] * n
        for i in range(n):
            dpi = dp0[i]
            for j, d0 in d[i]:
                dp[j] = min(dp[j], dpi + d0)
        if min(dp0) > ans:
            break
        dp0 = dp
    ans = min(ans, dp[0])
print(ans)