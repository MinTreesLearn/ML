# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys
from typing import List

"""
created by shhuan at 2020/3/14 18:05

"""

N, M = map(int, input().split())
A = [x+1 for x in range(N)]
B = []

count = sum([(i-1)//2 for i in range(1, N+1)])
if count < M:
    print(-1)
    exit(0)

while count > M:
    lastpop = A.pop()
    count -= (lastpop - 1) // 2
    if count >= M:
        if len(B) == 0:
            B.append(10**9)
        else:
            B.append(B[-1] - 2 ** 16)
    else:
        gap = M - count
        B.append(2 * (lastpop - gap) - 1)
        count += gap

A += B[::-1]
print(' '.join(map(str, A)))