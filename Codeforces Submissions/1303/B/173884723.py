from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(5*(10 ** 3))


T = ii()
for _ in range(T):
    N, G, B = mis()

    m = (N+1)//2

    ans = (m-1)//G*(G+B) + (m%G if m%G else G)
    print(max(N, ans))


