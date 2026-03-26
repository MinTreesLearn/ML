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

s="#"+S()
v=[[0] for i in range(26)]
for i in range(1,len(s)):
	for j in range(26):
		v[j]+=v[j][-1],
	v[ord(s[i])-97][-1]+=1
for i in range(I()):
	l,r=R()
	dif=0
	for i in range(26):
		if v[i][r]-v[i][l-1]:dif+=1
	if not r-l or s[r]!=s[l] or dif>=3:
		print('YES')
	else:
		print('NO')