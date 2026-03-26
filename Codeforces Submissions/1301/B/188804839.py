# 13:58-
import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
	N = int(input())
	A = list(map(int, input().split()))

	l,r = float('inf'),-1
	m = 0
	cur = 0
	for i in range(N):
		if A[i]!=-1:
			cur = A[i]
			if i-1>=0:
				if A[i-1]==-1:
					l = min(l,A[i])
					r = max(r,A[i])
				else:
					m = max(m, abs(A[i]-A[i-1]))
			if i+1<N:
				if A[i+1]==-1:
					l = min(l,A[i])
					r = max(r,A[i])
				else:
					m = max(m, abs(A[i]-A[i+1]))


	m = max(m, (r-l-1)//2+1)

	if r!=-1:
		cur = (l+r)//2

	print(m,cur)




