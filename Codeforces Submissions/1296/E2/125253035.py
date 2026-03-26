from collections import defaultdict, Counter,deque
from math import sqrt, log10, log, floor, factorial,gcd
from bisect import bisect_left, bisect_right
from itertools import permutations,combinations
import sys, io, os
input = sys.stdin.readline
# input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# sys.setrecursionlimit(10000)
inf = float('inf')
mod = 10 ** 9 + 7
def get_list(): return [int(i) for i in input().split()]
def yn(a): print("YES" if a else "NO")
ceil = lambda a, b: (a + b - 1) // b
def lis_length(nums, cmp=lambda x, y: x > y):
    P = [0] * len(nums)
    M = [0] * (len(nums) + 1)
    L = 0

    for i in range(len(nums)):
        lo, hi = 1, L

        while lo <= hi:
            mid = (lo + hi) // 2
            if cmp(nums[M[mid]], nums[i]):
                lo = mid + 1
            else:
                hi = mid - 1

        newL = lo
        P[i] = M[newL - 1]
        M[newL] = i

        L = max(L, newL)

    lislen=[1 for i in P]
    for i in range(1,len(nums)):
        if P[i]==0:
            if cmp(nums[P[i]],nums[i]):
                lislen[i]=lislen[P[i]]+1
            else:
                lislen[i]=lislen[P[i]]
        else:
            lislen[i] = lislen[P[i]] + 1
    return lislen
t=1
for i in range(t):
    n=int(input())
    s=input().strip()
    lislen=lis_length(s)
    print(max(lislen))
    print(*lislen)
