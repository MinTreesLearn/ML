from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
import random
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(2* 10 ** 5 + 1)



T = ii()
for _ in range(T):
    N, K = mis()
    A = list(mis())
    seen = set()

    ans = 'YES'
    for a in A:
        index = 0
        while a > 0:
            a, mod = divmod(a, K)
            if mod > 1:
                ans = 'NO'
                break 
            elif mod == 1 and index in seen:
                ans = 'NO'
                break
            elif mod == 1:
                seen.add(index)
            index += 1
        if ans == 'NO':
            break 
    print(ans)







