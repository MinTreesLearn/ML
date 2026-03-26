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
    N, M = mis()
    A = list(mis())

    C = [0] * 61
    sum = 0
    for a in A:
        C[int(log2(a))] += 1
        sum += a

    binn = format(N, 'b')[::-1]
    ans = 0
    if N > sum:
        print(-1)
        continue
    for i in range(len(binn)):
        if binn[i] == '0':
            pass
        elif C[i] > 0:
            C[i] -= 1
        else:
            j = i + 1
            while C[j] == 0:
                j += 1 
            C[j] -= 1
            C[j-1] += 1
            j -= 1
            ans += 1
            while j > i:
                ans += 1
                C[j-1] += 1
                j -= 1
        C[i+1] += C[i]//2
    print(ans)




