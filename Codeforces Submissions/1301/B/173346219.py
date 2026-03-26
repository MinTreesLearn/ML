import sys
from math import sqrt, gcd, factorial, ceil, floor, pi, inf
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
    ans = high
    while low<=high:
        mid = (low+high)//2
        #if arr[mid]==x:
        #    return mid
        if arr[mid][0]<=x:
            ans = mid
            low = mid+1
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



for _ in range(I()):
    n = I()
    a = L()
    x,y = inf,-1
    for i in range(n):
        if a[i]==-1:
            if i>0:
                if a[i-1]!=-1:
                    x = min(a[i-1],x)
                y = max(a[i-1],y)
            if i<(n-1):
                if a[i+1]!=-1:
                    x = min(a[i+1],x)
                y = max(a[i+1],y)
    if y==-1:
        print(0,1)
        continue
    k = (x+y)//2
    for i in range(n):
        if a[i]==-1:
            a[i]=k
    ans = -1
    for i in range(1,n):
        ans = max(ans,abs(a[i]-a[i-1]))
    print(ans,k)
    
    



































    
    
    
    
