import time
import os,sys
from datetime import datetime
from math import floor,sqrt,gcd,factorial,ceil,log2
from collections import Counter,defaultdict as dd
import bisect
from itertools import chain
from collections import deque
from sys import maxsize as INT_MAX
from itertools import permutations
from collections import deque
from functools import lru_cache
import threading
from heapq import *
from functools import cmp_to_key
from io import BytesIO, IOBase
'''Dont use setrecursionlimit in pypy'''
sys.setrecursionlimit(int(1e9))
#threading.stack_size(0x2000000)
ONLINE_JUDGE,INF,mod=False,float('inf'),int(1e9)+7
if os.path.exists('D:\\vimstuff'):
	ONLINE_JUDGE=True
	sys.stdin=open('D:\\vimstuff\\inp.txt','r')
	sys.stdout=open('D:\\vimstuff\\out.txt','w')

BUFSIZE: int = 8192
def readint():
	return int(sys.stdin.readline())
def readstr():
	return sys.stdin.readline()
def readlst():
	return list(map(int, sys.stdin.readline().strip().split()))
def readmul():
	return map(int, sys.stdin.readline().strip().split())
def mulfloat():	return map(float, sys.stdin.readline().strip().split())
def flush():
	return sys.stdout.flush()
def power_two(x):
	return (1<<x)
def lcm(a,b):
	return a*b//gcd(a,b)

def countGreater(arr,n, k):
	l = 0
	r = n - 1
	leftGreater = n
	while (l <= r):
		m = int(l + (r - l) / 2)
		if (arr[m] >= k):
			leftGreater = m
			r = m - 1
		else:
			l = m + 1
			return (n - leftGreater)

def lower_bound(arr,n,val):
	l,r=-1,n
	while r>l+1:
		m=int((l+r)>>1)
		if arr[m]<val:
			l=m
		else:
			r=m
	return r

def upper_bound(arr,n,val):
	l,r=-1,n
	while r>l+1:
		m=int((l+r)>>1)
		if arr[m]<=val:
			l=m
		else:
			r=m
	return l

def binpow(a,n,mod):
	res=1
	while n:
		if n&1:
			res=(res*a)%mod
			n-=1
		a=(a*a)%mod
		n=n>>1
	return res

def printmat(l,seperate=True):
	for i in range(0,len(l)):
		if(seperate):
			print(*l[i],sep=" ")
		else:
			print(*l[i],sep="")

def is_perfect_square(num):
	#print(num)
	temp = num**(0.5)
	#print(temp)
	return (temp//1)==temp

def find(res):
	n1=res
	while par[n1]!=n1:
		par[n1]=par[par[n1]]
		n1=par[n1]
	return n1

def union(u,v):
	p1,p2=find(u),find(v)
	if p1==p2:
		return 0
	if(rank[p1]>rank[p2]):
		p1,p2=p2,p1
	par[p1]=p2
	rank[p2]+=rank[p1]
	return 1

#Fibonaci logn implementation gives current and next fibonnaci number
def fibonac(n):
	if n==0:
		return (0,1)
	nb2,nb2p1=fibonac(n//2)
	#print(nb2)
	#print(nb2p1)
	a=nb2*(2*nb2p1-nb2)
	b=nb2p1*nb2p1+nb2*nb2
	if n&1==0:
		return (a,b)
	else:
		return (b,a+b)

def euler_totient(n):
	res=n
	for i in range(2,int(sqrt(n))+1):
		if res%i==0:
			while n%i==0:
				n=n//i

			res=res-res//i
	if n>1:
		res=res-res//n
	return res

def custom_ceil(a,b):
	return (a+b-1)//b

def iter_dfs(node,comp):
	stk=[node]
	vis=[False]*(comp+1)
	while len(stk):
		node=stk[-1]
		vis[node]=True
		stk=stk[:-1]
		for child in graph[node]:
			if child==comp:
				return True
			if vis[child]==False:
				vis[child]=True
				stk.append(child)
	return False

'''
1. Implement after understanding properly don't do in vain.
2. Check corner cases.
3. Use python if there is recursion.
4. Use pypy if heavy loop,list slice.
5. If you don't want to alter string do not use list costly.
'''
def john_3_16():
	n,x=readmul()
	a=readlst()
	mx=max(a)
	if x in a:
		print(1);return
	print(max(2,ceil(x/mx)))
	return

def main():
	#tc=1
	tc=readint()
	start=time.time()
	#cnt=1
	while tc:
		#john_3_16(cnt)
		john_3_16()
		tc-=1
		#cnt+=1
	if ONLINE_JUDGE:
		print(f'{(time.time()-start)*1000}ms')
		pass
main()

