from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
input=lambda:sys.stdin.buffer.readline()
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(5*(10 ** 3))

N, M, P = mis()
A = list(mis())
B = list(mis())

pi = None
pj = None
for i in range(N):
    if A[i] % P != 0:
        pi = i
        break
for j in range(M):
    if B[j] % P != 0:
        pj = j
        break
print(pi + pj)


