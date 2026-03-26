n, h, l, r = map(int, input().split())
arr = list(map(int, input().split()))
s = [0] * (n + 1)
for i in range(n):
    s[i + 1] = s[i] + arr[i]
dp = [[0] * (n + 1) for _ in range(n + 1)]
# dp[i][j] 为前i个数减j, 前i个数的最大分数
# dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + (l <= (s[i] - j) % h <= r)
for i in range(1, n + 1):
    for j in range(i + 1):
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + (l <= (s[i] - j) % h <= r)
print(max(dp[n]))
