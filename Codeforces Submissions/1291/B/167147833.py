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
    a = L()
    x = -1
    for i in range(n):
        if a[i]<i:
            break
        else:
            x=i
    y = n
    for i in range(n-1,-1,-1):
        if a[i]<n-1-i:
            break
        else:
            y=i
    if n-1-y==x and y>x:
        print("NO")
        continue
    if y-x<=1:
        print("YES")
    else:
        print("NO")
    
        
    
    
    
    
    
    
    
    
    
    