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
created by shhuan at 2020/3/19 13:35

"""


def check(s, a, b, after):
    ns, na, nb = len(s), len(a), len(b)
    if ns < na + nb:
        return False

    dp = [[0 for _ in range(nb+1)] for _ in range(na+1)]
    for i in range(na+1):
        for j in range(nb+1):
            if i == 0 and j == 0:
                continue
            dp[i][j] = min(after[dp[i-1][j]][a[i-1]] if i > 0 else ns, after[dp[i][j-1]][b[j-1]] if j > 0 else ns) + 1

    return dp[na][nb] <= ns


def solve(s, t):
    ns = len(s)
    after = [[ns for _ in range(26)] for _ in range(ns+2)]
    for i in range(ns-1, -1, -1):
        for j in range(26):
            after[i][j] = after[i+1][j]
        after[i][s[i]] = i

    for i in range(len(t)):
        a, b = t[:i], t[i:]
        if check(s, a, b, after):
            return 'YES'

    return 'NO'


T = int(input())
ans = []
for i in range(T):
    s = input()
    t = input()
    s = [ord(v) - ord('a') for v in s]
    t = [ord(v) - ord('a') for v in t]
    ans.append(solve(s, t))

print('\n'.join(ans))