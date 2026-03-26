import sys
from math import sqrt, gcd, factorial, ceil, floor, pi, inf
from collections import deque, Counter, OrderedDict
from heapq import heapify, heappush, heappop
#sys.setrecursionlimit(10**6)
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


n,a,b,k = M()
h = L()
for i in range(n):
    if h[i]%(a+b)==0:
        h[i]=a+b
    else:
        h[i] = (h[i]%(a+b))
ans = 0
p = []
for i in h:
    if i<=a:
        ans+=1
    else:
        p.append(((i-a-1)//a)+1)
p.sort()
for i in p:
    if k<i:
        break
    ans+=1
    k-=i
print(ans)

    
    









    
    
    
    
