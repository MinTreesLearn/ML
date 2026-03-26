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
    n,s,k = M()
    a = L()
    dic = {}
    for i in a:
        dic[i]=1
    ans,a2=inf,inf
    for i in range(s,n+1):
        if i not in dic.keys():
            ans = i-s
            break
    for i in range(s-1,0,-1):
        if i not in dic.keys():
            a2 = s-i
            break
    print(min(ans,a2))
    
    
    
    