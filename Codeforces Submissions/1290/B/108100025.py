def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input()))


s = S()[:-1]

n = len(s)

dp = [[0 for i in range(n)] for j in range(26)]
dp1= [0 for i in range(n+1)]

for i in range(26):
	count = 0
	for j in range(len(s)):
		if (ord(s[j])-97)==i:
			count+=1
			dp[i][j] = count
		else:
			dp[i][j] = count

q, = I()
for t1 in range(q):
	l,r = I()
	if abs(l-r)>=1:
		if s[l-1]!=s[r-1]:
			print('Yes')
		else:
			count = 0
			for k in range(len(dp)):
				if dp[k][l-1]!=dp[k][r-1]:
					count+=1
			if count>=3:				
				print('Yes')
			else:
				print('No')
	else:
		print('Yes')

