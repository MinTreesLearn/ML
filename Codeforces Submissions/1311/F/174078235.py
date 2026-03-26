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

class ft:
    def __init__(self, n):
        self.n = n
        self.a = [0] * (n+1)
    def update(self, i, val):
        i += 1
        while i <= self.n:
            self.a[i] += val 
            i += i & (-i)
    def query(self, i):
        r = 0
        i += 1
        while i > 0:
            r += self.a[i]
            i -= i & -i
        return r

N = ii()
X = list(mis())
V = list(mis())
XV = list(zip(X, V))

XV.sort()
V.sort()

fw_cnt = ft(N)
fw_sum = ft(N)

ans = 0
for i, (x, v) in enumerate(XV):
    pos = bisect_right(V, v) - 1
    ans += x*fw_cnt.query(pos) - fw_sum.query(pos)
    fw_cnt.update(pos, 1)
    fw_sum.update(pos, x)

print(ans)












