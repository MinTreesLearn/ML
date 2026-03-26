mod=int(1e9+7)

def read():
	return [int(i) for i in input().split()]

def main():
	n,m=read()
	dp=[[0 for i in range(n+2)] for i in range(n+2)]
	for i in range(1,n+1):
		for j in range(i,n+1):
			dp[i][j]=1

	for _ in range(m-1):
		for i in range(1,n+1):
			for j in range(n,i-1,-1):
				dp[i][j]=(dp[i][j]+dp[i][j+1]+dp[i-1][j]-dp[i-1][j+1]+mod)%mod
	ans=0
	for i in range(1,n+1):
		for j in range(i,n+1):
			ans=(ans+dp[i][j])%mod
	print(ans)


main()