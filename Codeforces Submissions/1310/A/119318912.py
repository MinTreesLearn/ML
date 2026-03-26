from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
from heapq import heapify,heappush,heappop,heappushpop
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

n=I()
a=sorted(zip(L(),L()))
d=defaultdict(list)
d[a[0][0]]=[a[0][1]]
ex=0
v=[a[0][0]]
for i in range(1,n):
	if a[i][0]!=a[i-1][0]:
		v.extend([0]*min(ex,a[i][0]-a[i-1][0]-1)+[a[i][0]])
		ex-=min(ex,a[i][0]-a[i-1][0]-1)
	else:
		ex+=1
	d[a[i][0]]+=a[i][1],
v.extend([0]*ex)
hp=[]
val=defaultdict(list)
ans=0
#print(v,d)
for j in range(n):
	if v[j]:
		i=v[j]
		for el in d[i]:
			val[el]+=j,
			heappush(hp,-el)
	p=-heappop(hp)
	ans+=p*(j-val[p].pop())
	#print(ans)
print(ans)