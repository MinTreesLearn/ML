def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input().split()))


t,=I()
for t1 in range(t):
	n,m,k = I()
	a   = I()
	a = [0]+a
	dp = [0]*(m)
	for i in range(m):
		dp[i] = max(a[i+1],a[n-m+i+1])
	max1 = 0
	for i in range(len(dp)):
		min1 = dp[i]
		for j in range(i,len(dp)):
			min1 = min(min1,dp[j])
			if (i+len(dp)-j-1)<=k:
				min1 = min(min1,dp[j])
				max1 = max(max1,min1)
	print(max1)
