from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
from heapq import heapify,heappush,heappushpop
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\r\n')
L=lambda:list(R())
P=lambda x:stdout.write(str(x)+'\n')
lcm=lambda x,y:(x*y)//gcd(x,y)
nCr=lambda x,y:(f[x]*inv((f[y]*f[x-y])%N))%N
inv=lambda x:pow(x,N-2,N)
sm=lambda x:(x**2+x)//2
N=10**9+7

n,m=R()
a=[[] for i in range(n+1)]
b=[[] for i in range(n+1)]
for i in range(m):
	x,y=R()
	a[y]+=x,
	b[x]+=y,
k=I()
v=L()
stk=deque([v[-1]])
vst=[False]*(n+1)
val=[1]*(n+1)
val[stk[-1]]=0
vst[stk[-1]]=True
while stk:
	p=stk.pop()
	for el in a[p]:
		if not vst[el]:
			val[el]+=val[p]
			stk.appendleft(el)
			vst[el]=True
mn=0
mx=0
for j in range(k-1):
	i=v[j]
	cnt=0
	p=inf
	#print(i,b[i])
	for el in b[i]:
		if val[el]<p:
			p=val[el]
			cnt=1
		elif val[el]==p:
			cnt+=1
	#print(cnt,p,val[j+1],val[1:])
	if p<val[v[j+1]]:
		mx+=1
		mn+=1
	else:
		if cnt>1:
			mx+=1
print(mn,mx)