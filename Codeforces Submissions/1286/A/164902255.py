import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
p = [0] + list(map(int, input().split()))
inf = pow(10, 9) + 1
dp1 = [[inf] * (n + 1) for _ in range(n + 1)]
dp2 = [[inf] * (n + 1) for _ in range(n + 1)]
dp1[0][0] = 0
dp2[0][0] = 0
for i in range(1, n + 1):
    pi = p[i]
    for j in range(i):
        if pi % 2:
            dp1[i][j] = min(dp1[i][j], dp1[i - 1][j], dp2[i - 1][j] + 1)
        elif not pi % 2 and pi:
            dp2[i][j + 1] = min(dp2[i][j + 1], dp1[i - 1][j] + 1, dp2[i - 1][j])
        else:
            dp1[i][j] = min(dp1[i][j], dp1[i - 1][j], dp2[i - 1][j] + 1)
            dp2[i][j + 1] = min(dp2[i][j + 1], dp1[i - 1][j] + 1, dp2[i - 1][j])
ans = min(dp1[n][n // 2], dp2[n][n // 2])
print(ans)