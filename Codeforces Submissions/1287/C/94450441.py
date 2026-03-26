n=int(input())
p=list(map(int,input().split()))
inf=10**12
dp=[[[inf,inf] for j in range(101)] for i in range(n)]
if p[0]!=0:
    if p[0]%2==0:
        dp[0][1][0]=0
    else:
        dp[0][0][1]=0
else:
    dp[0][1][0]=0
    dp[0][0][1]=0
for i in range(1,n):
    for j in range(101):
        for k in range(2):
            if dp[i-1][j][k]==inf:
                continue
            if p[i]!=0:
                if p[i]%2==0:
                    if k==0:
                        dp[i][j+1][0]=min(dp[i-1][j][k],dp[i][j+1][0])
                    else:
                        dp[i][j+1][0]=min(dp[i-1][j][k]+1,dp[i][j+1][0])
                else:
                    if k==0:
                        dp[i][j][1]=min(dp[i-1][j][k]+1,dp[i][j][1])
                    else:
                        dp[i][j][1]=min(dp[i-1][j][k],dp[i][j][1])
            else:
                if k==0:
                    dp[i][j+1][0]=min(dp[i-1][j][k],dp[i][j+1][0])
                else:
                    dp[i][j+1][0]=min(dp[i-1][j][k]+1,dp[i][j+1][0])
                if k==0:
                    dp[i][j][1]=min(dp[i-1][j][k]+1,dp[i][j][1])
                else:
                    dp[i][j][1]=min(dp[i-1][j][k],dp[i][j][1])
print(min(dp[-1][n//2]))