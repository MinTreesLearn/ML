import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]
for i in range(n):
    dp[i][i] = a[i]
for i in range(2, n + 1):
    for l in range(n - i + 1):
        r = l + i - 1
        dpl = dp[l]
        for j in range(l, r):
            c = dpl[j]
            if c and not c ^ dp[j + 1][r]:
                dpl[r] = c + 1
                break
inf = pow(10, 9) + 1
dp1 = [inf] * (n + 1)
dp1[0] = 0
for i in range(n):
    dpi = dp[i]
    c = dp1[i]
    for j in range(i, n):
        if dpi[j]:
            dp1[j + 1] = min(dp1[j + 1], c + 1)
ans = dp1[n]
print(ans)