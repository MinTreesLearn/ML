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

# import pypyjit
# pypyjit.set_param('max_unroll_recursion=-1')
inf = float('inf')
eps = 10 ** (-15)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

"""
交差しない２つの区間
これの最大値　適当に区切ってみる
いくつを作るか　Nは小さい　区間スケジュール
"""

N = getN()
A = [0] + getList()
for i in range(1, N + 1):
    A[i] += A[i - 1]

d = defaultdict(list)
for i in range(N):
    for j in range(i, N):
        l = A[j + 1] - A[i]
        d[l].append((i, j))

ans1 = 0
ans2 = []
for _, l in d.items():
    l.sort(key = lambda i:i[1])
    c = 0
    last = l[0][1]
    opt = [l[0]]
    for i in range(1, len(l)):
        if l[i][0] <= last:
            c += 1
        else:
            last = l[i][1]
            opt.append(l[i])
    if len(l) - c > ans1:
        ans1 = len(l) - c
        ans2 = opt

print(ans1)
for l, r in ans2:
    print(l + 1, r + 1)