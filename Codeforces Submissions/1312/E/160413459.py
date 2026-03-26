import sys
from collections import defaultdict, deque, Counter
from decimal import *
from heapq import heapify, heappop, heappush
import math
import random
import string
from copy import deepcopy
from itertools import combinations, permutations, product
from operator import mul, itemgetter
from functools import reduce
from bisect import bisect_left, bisect_right

def input():
    return sys.stdin.readline().rstrip()
def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getListGraph():
    return list(map(lambda x:int(x) - 1, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]

mod = 10 ** 9 + 7
MOD = 998244353
# sys.setrecursionlimit(10000000)
# import pypyjit
# pypyjit.set_param('max_unroll_recursion=-1')
inf = float('inf')
eps = 10 ** (-12)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

N = getN()
A = getList()
# dp[left][right]
dp = [[-i] * (N + 1) for i in range(N + 1)]
for i in range(N):
    dp[i][i + 1] = A[i]
E = [[] for i in range(N + 1)]

# 開区間で持つ 区間dpでN!→N^3に
for i in range(1, N + 1):
    for j in range(N - i + 1):
        # 区間を２分割 (j, j + k), (j + k, j + i)
        for k in range(1, i):
            if dp[j][j + k] == dp[j + k][j + i]:
                # これは一意
                dp[j][j + i] = dp[j][j + k] + 1
        if dp[j][j + i] > 0:
            E[j + i].append(j)

dis = [inf] * (N + 1)
dis[0] = 0
for v in range(1, N + 1):
    for u in E[v]:
        dis[v] = min(dis[v], dis[u] + 1)
print(dis[-1])