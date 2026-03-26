from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(5*(10 ** 3))

T = ii()
for _ in range(T):
    N = ii()
    S = input()
    strs = []
    for k in range(1, N+1):
        if (N-k+1) % 2 == 0:
            strs.append((S[k-1:] + S[:k-1], k))
        else:
            strs.append((S[k-1:] + S[:k-1][::-1], k))
    strs.sort()
    print(strs[0][0])
    print(strs[0][1])
    




