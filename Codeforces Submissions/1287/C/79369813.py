n=int(input())
s=list(map(int,input().split()))
dp=[[[float("INF"),float("INF")]for i in range(n//2+1)]for i in range(n+1)]
 
dp[0][0]=[0,0]
 
for i in range(1,n+1):
	if s[i-1]==0:
		for j in range(1,n//2+1):
			dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1)
		for j in range(n//2+1):
			dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1])
	else:
		if s[i-1]%2==0:
			for j in range(1,n//2+1):
				dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1)
		else:
			for j in range(n//2+1):
				dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1])
print(min(dp[-1][-1]))

 		 							  	 		  	  					  	