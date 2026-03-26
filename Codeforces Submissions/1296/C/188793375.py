# 11:59-
import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import defaultdict


for _ in range(int(input())):
	N = int(input())
	S = input()

	cur = float('inf')
	ans = []

	lib = {}
	lib[(0,0)] = -1
	r,l = 0,0
	for i,c in enumerate(S):
		if c=='U':
			r+=1
		elif c=='D':
			r-=1
		elif c=='L':
			l-=1
		else:
			l+=1

		if (r,l) in lib:
			t = i-lib[(r,l)]
			if t<cur:
				ans = (lib[(r,l)]+2,i+1)
				cur = t
		lib[(r,l)] = i

	if cur==float('inf'):
		print(-1)
	else:
		print(*ans)




	



