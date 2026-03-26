mm = 102
t = 1
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    dp = []
    
    for i in range(mm):
        dp.append([])
        for j in range(mm):
            dp[-1].append([1e9, 1e9])

    dp[0][0][0]=0
    dp[0][0][1]=0
    for i in range(1, n+1):
        for j in range(0, i+1):
            if(a[i-1]&1 == 0):
                dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1)
            if(a[i-1]&1 or a[i-1]==0):
                dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1])
	


    ans = min(dp[n][n//2][0],dp[n][n//2][1])
    print(ans)
