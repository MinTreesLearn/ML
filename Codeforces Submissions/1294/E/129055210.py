from collections import defaultdict, deque, Counter
from heapq import heapify, heappop, heappush
import math
from copy import deepcopy
from itertools import combinations, permutations, product, combinations_with_replacement
from bisect import bisect_left, bisect_right

import sys
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
# sys.setrecursionlimit(1000000)
inf = float('inf')
eps = 10 ** (-10)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

N, M = getNM()
mat = [getList() for i in range(N)]

ans = 0
# 各列ごと
for j in range(M):
    opt = inf
    cnt = [0] * N # t回回転
    for i in range(N):
        if (mat[i][j] - (j + 1)) % M == 0 and (mat[i][j] - (j + 1)) // M < N:
            time = (i - (mat[i][j] - (j + 1)) // M) % N
            cnt[time] += 1
    for i in range(N):
        opt = min(opt, i + (N - cnt[i]))
    ans += opt
    
print(ans)