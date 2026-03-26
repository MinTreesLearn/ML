import sys
input=lambda:sys.stdin.readline().rstrip()
N=int(input())
B=list(map(int,input().split()))
dp={}
ans=-float('inf')
for i in range(N):
	if not i-B[i] in dp:
		dp[i-B[i]]=0
	dp[i-B[i]]+=B[i]
	ans=max(ans,dp[i-B[i]])
print(ans)