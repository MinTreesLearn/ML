

import sys
input = lambda: sys.stdin.readline().strip()

def get_cross(a,b):
	A = [a,b]
	A.sort()

	if A[0][1]<A[1][0]:return None,None

	return max(A[0][0],A[1][0]),min(A[0][1],A[1][1])

for _ in range(int(input())):
	N,M = map(int, input().split())
	A = []
	for _ in range(N):
		t,l,h = map(int, input().split())
		A.append((t,l,h))
	A.sort()
	
	low,high = M,M
	pre=0
	ok = True
	for t,l,h in A:
		low-=t-pre
		high+=t-pre
		pre=t

		low,high=get_cross((l,h),(low,high))
		if low==None:
			ok = False
			break
	
	print('YES' if ok else 'NO')


