import sys
import math,bisect,operator
inf,mod = float('inf'),10**9+7
sys.setrecursionlimit(10 ** 5)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
I = lambda : int(sys.stdin.readline())
neo = lambda : map(int, sys.stdin.readline().split())
Neo = lambda : list(map(int, sys.stdin.readline().split()))
n = I()
a = Neo()
dp = [[[1000, 1000] for i in range(n + 1)] for j in range(n + 1)]
dp[0][0][0] = dp[0][0][1] = 0
for i in range(1, n + 1):
    k = a[i - 1]
    for j in range(i + 1):
        if k & 1 or k == 0:
            dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1])
        if k & 1 == 0:
            dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1)
print(min(dp[n][n >> 1]))
