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
        if arr[mid]==x:
            return x
        if arr[mid]<x:
            low = mid+1
        else:
            high = mid-1
            ans = arr[mid]
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

def f(x,y):
    b = []
    for i in range(k):
        if x[i]==y[i]:
            b.append(x[i])
        else:
            if x[i]=='S':
                if y[i]=='E':
                    b.append('T')
                else:
                    b.append('E')
            elif x[i]=='E':
                if y[i]=='S':
                    b.append('T')
                else:
                    b.append('S')
            else:
                if y[i]=='S':
                    b.append('E')
                else:
                    b.append('S')
    return "".join(b)
n,k = M()
a = []
d = {}
ans = 0
for _ in range(n):
    s = S()
    a.append(s)
    d[s]=0
for i in range(n-1):
    for j in range(i+1,n):
        if f(a[i],a[j]) in d:
            ans+=1
print(ans//3)
    
    
    
    
    






    





    
    
    
    
