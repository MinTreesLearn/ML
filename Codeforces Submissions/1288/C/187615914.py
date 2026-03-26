mod=int(1e9+7)

def read():
	return [int(i) for i in input().split()]


"""
	dp[i][j]: dp[i+x][j-x]
	next[i][j]: dp[i][j]+dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]

	increasing in a, decreasing in b

	ndp[i][j]: dp[i][j] + dp[i][j+1] + dp[i-1][j]

"""

def main():
	n,m=read()
	# a: increasing, b: decreasing
	# b[i] >= a[i]
	# dp:[p][q] : a[i]=p, b[i]=q
	dp=[[0 for i in range(n+2)] for i in range(n+2)]
	for i in range(1,n+1):
		for j in range(i,n+1):
			dp[i][j]=1

	for _ in range(m-1):
		ndp=[[0 for i in range(n+2)] for i in range(n+2)]
		for i in range(1,n+1):
			for j in range(n,i-1,-1):
				ndp[i][j]+=dp[i][j]+ndp[i][j+1]+ndp[i-1][j]-ndp[i-1][j+1]+mod
				ndp[i][j]%=mod
		dp=ndp
	ans=0
	for i in range(1,n+1):
		for j in range(i,n+1):
			ans=(ans+dp[i][j])%mod
	print(ans)


main()