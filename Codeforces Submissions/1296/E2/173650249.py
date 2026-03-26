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

N = ii()
S = input()

edges = defaultdict(list)
color = [-1] * N

lis = []

for i, c in enumerate(S):
    od = 26 - (ord(c) - ord('a'))
    index = bisect_left(lis, od)
    if index == len(lis):
        lis.append(od)
    else:
        lis[index] = od
    color[i] = index + 1

print(len(lis))
print(*color)









    





