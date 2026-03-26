n = int(input())
p = list(map(int, input().split()))
if n==1:
    print(0)
    exit(0)
if sum(p)==0:
    print(1)
    exit(0)
INF = 100
dp = [[INF]*2 for _ in range(n//2+1)]
if p[0]==0:
    dp[1][0] = 0
    dp[0][1] = 0
elif p[0]%2:
    dp[0][1] = 0
else:
    dp[1][0] = 0
for i in range(1, n):
    newdp = [[INF]*2 for _ in range(n//2+1)]
    if p[i]==0:
        for j in range(n//2+1):
            newdp[j][1] = min(dp[j][1], dp[j][0]+1)
            if j==n//2:
                break
            newdp[j+1][0] = min(dp[j][0], dp[j][1]+1)
    elif p[i]%2:
        for j in range(n//2+1):
            newdp[j][1] = min(dp[j][1], dp[j][0]+1)
    else:
        for j in range(n//2):
            newdp[j+1][0] = min(dp[j][0], dp[j][1]+1)
    dp = newdp
print(min(dp[-1]))