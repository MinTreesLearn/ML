import random
import sys
readline=sys.stdin.readline

N,K=map(int,readline().split())
A=[list(map(int,readline().split())) for i in range(N)]
inf=1<<30
ans=inf
for _ in range(1<<13):
    bipartite=[[] for i in range(2)]
    for i in range(N):
        bipartite[random.randint(0,1)].append(i)
    dp=[inf]*N
    dp[0]=0
    for _ in range(K):
        prev=dp
        dp=[inf]*N
        for i in bipartite[0]:
            for j in bipartite[1]:
                dp[j]=min(dp[j],prev[i]+A[i][j])
                dp[i]=min(dp[i],prev[j]+A[j][i])
    ans=min(ans,dp[0])
print(ans)