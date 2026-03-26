import sys
from math import sqrt, gcd, factorial, ceil, floor, pi, inf, isqrt, lcm
from collections import deque, Counter, OrderedDict, defaultdict
from heapq import heapify, heappush, heappop
#sys.setrecursionlimit(10**5)
from functools import lru_cache
#@lru_cache(None)

#======================================================#
input = lambda: sys.stdin.readline()
I = lambda: int(input().strip())
S = lambda: input().strip()
M = lambda: map(int,input().strip().split())
L = lambda: list(map(int,input().strip().split()))
#======================================================#

#======================================================#

def factorial_inverse():
    mod=10**9+7
    upto=(10**5)*3+1 
    nfactorial=[1 for i in range(upto)]
    ninverse=[1 for i in range(upto)]
    finverse=[1 for i in range(upto)]
    for i in range(2,upto):
        nfactorial[i]=(nfactorial[i-1]*i)%mod
        ninverse[i]=(-(mod//i)*ninverse[mod%i])%mod
        finverse[i]=(finverse[i-1]*ninverse[i])%mod
    return nfactorial,finverse

def nCk(n,k):
    if n<0 or k<0:
        return 0
    if k>n:
        return 0
    return ((nfactorial[n]*finverse[k]%mod)*finverse[n-k])%mod
#======================================================#
def primelist():
    L = [False for i in range((10**10)+1)]
    primes = [False for i in range((10**10)+1)]
    for i in range(2,(10**10)+1):
        if not L[i]:
            primes[i]=True
            for j in range(i,(10**10)+1,i):
                L[j]=True
    return primes
def isPrime(n):
    p = primelist()
    return p[n]
#======================================================#
def bst(arr,x):
    low,high = 0,len(arr)-1
    ans = -1
    while low<=high:
        mid = (low+high)//2
        #if arr[mid]==x:
        #    return mid
        if arr[mid]<=x:
            low = mid+1
        else:
            high = mid-1
            ans = mid
    return ans
    
    
def factors(x):
    l1 = []
    l2 = []
    for i in range(1,int(sqrt(x))+1):
        if x%i==0:
            if (i*i)==x:
                l1.append(i)
            else:
                l1.append(i)
                l2.append(x//i)
    for i in range(len(l2)//2):
        l2[i],l2[len(l2)-1-i]=l2[len(l2)-1-i],l2[i]
    return l1+l2
#======================================================#

def power(n,x):
    if x==0:
        return 1
    k = (10**9)+7
    if n==1:
        return 1
    if x==1:
        return n
    ans = power(n,x//2)
    if x%2==0:
        return (ans*ans)%k
    return (ans*ans*n)%k

#======================================================#

def f():
    b = [[a[0],1]]
    c = a[0]
    for i in range(1,n):
        if b[-1][0]==a[i]:
            b[-1][1]+=1
            c+=a[i]
        elif b[-1][0]<a[i]:
            b.append([a[i],1])
            c+=a[i]
        else:
            t = 1
            while b:
                if b[-1][0]<a[i]:
                    break
                else:
                    c-=b[-1][0]*b[-1][1]
                    t+=b[-1][1]
                    b.pop()
            b.append([a[i],t])
            c+=a[i]*t
        l.append(c)
    
n = I()
a = L()
l = [a[0]]
f()
ans = l
a.reverse()
l = [a[0]]
f()
l.reverse()
a.reverse()
res = 0
for i in range(1,n):
    if (ans[i]+l[i]-a[i])>(ans[res]+l[res]-a[res]):
        res = i
pp = [0 for i in range(n)]
pp[res]=a[res]
for i in range(res+1,n):
    pp[i] = min(a[i],pp[i-1])
for i in range(res-1,-1,-1):
    pp[i] = min(a[i],pp[i+1])
print(*pp)

















    





    
    
    
    
