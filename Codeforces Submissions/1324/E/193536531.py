n, h, L, R = map(int, input().split())
w = [0] + list(map(int, input().split()))
dp = [[-1 << 31] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    w[i] += w[i - 1]
dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(1, i + 1):
        s1 = (w[i] - j) % h
        s2 = (w[i] - j + 1) % h
        dp[i][j] = dp[i - 1][j - 1]
        if s1 >= L and s1 <= R:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
        dp[i][j - 1] = max(dp[i - 1][j - 1], dp[i][j - 1])
        if s2 >= L and s2 <= R:
            dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j - 1] + 1)
print(max(dp[n]))