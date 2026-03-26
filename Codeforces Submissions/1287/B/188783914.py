# 08:58-
import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import defaultdict,Counter

N,K = map(int, input().split())
A = []
for _ in range(N):
	A.append(input())

B = set(A)

# EST
ans = 0
for i in range(N-1):
	for j in range(i+1,N):
		key = []
		for k in range(K):
			if A[i][k]==A[j][k]:
				key.append(A[i][k])
			else:
				tmp = [A[i][k],A[j][k]]
				if 'S' not in tmp:
					key.append('S')
				elif 'E' not in tmp:
					key.append('E')
				else:
					key.append('T')
		key = ''.join(key)
		if key in B:
			ans+=1

print(ans//3)



