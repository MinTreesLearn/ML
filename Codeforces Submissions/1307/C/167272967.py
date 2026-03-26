# 22:32-

import sys
input = lambda: sys.stdin.readline().strip()

from collections import Counter,defaultdict

def get_sums(A):
	sum1 = []
	for i in range(len(A)):
		a,c = A[i]
		t = [0]*26 if not sum1 else sum1[-1][::]
		t[ord(a)-ord('a')]+=c
		sum1.append(t)
	return sum1

S = input()
C = Counter(S)

ans = 0
for k,v in C.items():
	ans = max(ans,v,v*(v-1)//2)

A=[]
for c in S:
	if not A or c!=A[-1][0]:
		A.append([c,1])
	else:
		A[-1][1]+=1
M = len(A)


sum1 = get_sums(A)
sum2 = get_sums(A[::-1])[::-1]

chars = [chr(c) for c in range(ord('a'),ord('z')+1)]

lib = defaultdict(int)
for i,[a,c] in enumerate(A):
	for c1 in chars:
		if c1==a:continue
		lib[a+c1]+=c*sum2[i][ord(c1)-ord('a')]

for k,v in lib.items():
	ans = max(ans, v)

print(ans)
	
	
