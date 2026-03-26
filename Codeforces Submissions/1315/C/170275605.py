import sys
from math import sqrt, gcd, factorial, ceil, floor, pi, inf
from collections import deque, Counter, OrderedDict
from heapq import heapify, heappush, heappop
#sys.setrecursionlimit(10**6)

#======================================================#
input = lambda: sys.stdin.readline()
I = lambda: int(input().strip())
S = lambda: input().strip()
M = lambda: map(int,input().strip().split())
L = lambda: list(map(int,input().strip().split()))
#======================================================#

#======================================================#
def primelist():
    L = [False for i in range(10**9)]
    primes = [False for i in range(10**9)]
    for i in range(2,10**9):
        if not L[i]:
            primes[i]=True
            for j in range(i,10**9,i):
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
            return mid
        elif arr[mid]<x:
            ans = mid
            low = mid+1
        else:
            high = mid-1
    return ans
#======================================================#

for _ in range(I()):
    n = I()
    b = L()
    d = {i+1:False for i in range(2*n)}
    a = [0 for i in range(2*n)]
    f = True
    for i in range(n):
        a[2*i]=b[i]
        if b[i]>2*n:
            f = False
            break
        d[b[i]]=True
    if not f:
        print(-1)
        continue
    f = True
    for i in range(1,2*n,2):
        j=a[i-1]+1
        if j==(2*n+1):
            f = False
            break
        while d[j]:
            j+=1
            if j==(2*n+1):
                f = False
                break
        if not f:
            break
        a[i]=j
        d[j]=True
    if f:
        print(*a)
    else:
        print(-1)
    
    






