import sys
from math import sqrt, gcd, factorial, ceil, floor, pi, inf, isqrt, lcm
from collections import deque, Counter, OrderedDict, defaultdict
from heapq import heapify, heappush, heappop
#from sortedcontainers import SortedList
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

def bs(arr,x):
    low,high = 0,len(arr)-1
    ans = len(arr)
    while low<=high:
        mid = (low+high)//2
        #if arr[mid]==x:
        #    return x
        if arr[mid]<x:
            low = mid+1
        else:
            high = mid-1
            ans = mid
    return ans
    

def addd(arr,x):
    t = bs(arr,x)
    ans = []
    if t!=0:
        ans = arr[:t]
    ans.append(x)
    if t!=len(arr):
        ans.extend(arr[t:])
    return ans




#======================================================#

def factorial_inverse():
    mod=10**9+7
    upto=(10**3)*2+1 
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
            ans = mid
        else:
            high = mid-1
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

def f(b):
    a = p[:]
    b = format(b,'b')
    for i in range(len(b)):
        if b[len(b)-1-i]=='1':
            a[31-i]-=1
    ans = []
    for i in a:
        if i>0:
            ans.append("1")
        else:
            ans.append("0")
    b = int(b,2)
    return b-(int("".join(ans),2)&b)
    
    

n = I()
a = L()
p = [0 for i in range(32)]
for i in a:
    b = format(i,'b')
    for j in range(len(b)):
        if b[len(b)-1-j]=='1':
            p[31-j]+=1
t = 0
q = f(a[0])
for i in range(1,n):
    if f(a[i])>q:
        t = i
        q = f(a[i])
a[0],a[t] = a[t],a[0]
print(*a)





















    
    
    
    
