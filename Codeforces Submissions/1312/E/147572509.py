import sys
input = sys.stdin.readline
INF = float('inf')

n = int(input())
a = list(map(int, input().split()))
dp = [[INF] * (n + 2) for i in range(n + 1)]
cur = [[-1] * (n + 2) for i in range(n + 1)]

for i in range(n):
  dp[i][i + 1] = 1
  cur[i][i + 1] = a[i]


for d in range(2, n + 1):
  for l in range(n):
    r = l + d
    if r > n + 1:
      break

    for mid in range(l + 1, r):
      if cur[l][mid] == cur[mid][r] and cur[l][mid]!= -1:
        dp[l][r] = dp[l][mid]
        cur[l][r] = cur[l][mid] + 1
      else:
        dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid][r])

print(dp[0][n])
