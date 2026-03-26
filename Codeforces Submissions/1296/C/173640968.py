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
#sys.setrecursionlimit(10 ** 7)

T = ii()

for _ in range(T):
    index = {}
    i, j = 0, 0
    index[(0,0)] = -1
    ans = inf
    left, right = 0, 0
    N = ii()
    path = input()

    for cur_index, c in enumerate(path):
        if c == 'L':
            ni, nj = i, j - 1
        elif c == 'R':
            ni, nj = i, j + 1
        elif c == 'D':
            ni, nj = i + 1, j
        else:
            ni, nj = i - 1, j
        if (ni, nj) in index:
            if ans > cur_index - index[(ni, nj)] + 1:
                ans = cur_index - index[(ni, nj)] + 1
                left = index[(ni, nj)] + 2 
                right = cur_index + 1
        index[(ni, nj)] = cur_index 
        i, j = ni, nj

    if ans == inf:
        print(-1)
    else:
        print(left, right)




    



