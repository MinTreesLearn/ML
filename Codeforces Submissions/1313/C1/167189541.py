# 15:02-

import sys
input = lambda: sys.stdin.readline().strip()

N = int(input())
M = list(map(int, input().split()))

def deal(top,A):
	arr = []
	ans = 0
	for a in A:
		if a>top:
			a=top
		else:
			top=a
		ans+=a
		arr.append(a)
	return ans,arr

cnt=0
ans=[]
for i in range(N):
	A = M[:i][::-1]
	B = M[i+1:]
	t1,a1=deal(M[i],A)
	t2,a2=deal(M[i],B)
	t = t1+t2+M[i]
	if t>cnt:
		cnt=t
		ans = a1[::-1]+[M[i]]+a2

#print(cnt)
print(*ans)
