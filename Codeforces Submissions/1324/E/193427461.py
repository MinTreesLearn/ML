n,h,l,r = list(map(int,input().split()))
a = list(map(int,input().split()))
total = 0
dp = [[-10**9]*(n + 1) for _ in range(n + 1)]
dp[0][0] = 0
for i in range(1,n+1):
    total += a[i - 1]
    total %= h
    dp[i][0] = int(total >= l and total <= r) + dp[i - 1][0]
    for j in range(1,i + 1):
        dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1]) + int((total - j)%h >= l and (total - j)%h <= r)
print(max(dp[-1]))