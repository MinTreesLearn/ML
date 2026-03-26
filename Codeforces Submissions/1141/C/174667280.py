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

n = I()
a = L()
x,y = 0,0
s = 0
for i in a:
    s+=i
    x = min(x,s)
    y = max(y,s)
if (-x+y+1)==n:
    ans = [1-x]
    for i in a:
        ans.append(ans[-1]+i)
    if len(set(ans))!=n:
        print(-1)
    else:
        print(*ans)
else:
    print(-1)













    
    
    
    
