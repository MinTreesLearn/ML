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

inf = float('inf')
eps = 10 ** (-15)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

N = getN()
E = [[] for i in range(N)]

for _ in range(N - 1):
    a, b = getNM()
    E[a - 1].append(b - 1)
    E[b - 1].append(a - 1)

q = deque([0])
dis = [-1] * N
dis[0] = 0
while q:
    u = q.popleft()
    for v in E[u]:
        if dis[v] == -1:
            dis[v] = dis[u] + 1
            q.append(v)

s = dis.index(max(dis))

q = deque([s])
dis = [-1] * N
dis[s] = 0
par = [-1] * N
while q:
    u = q.popleft()
    for v in E[u]:
        if dis[v] == -1:
            dis[v] = dis[u] + 1
            par[v] = u
            q.append(v)


e = dis.index(max(dis))
ans = dis[e]
dis = [-1] * N
dis[e] = 0
q = deque([e])
now = e
while now != s:
    now = par[now]
    q.append(now)
    dis[now] = 0

while q:
    u = q.popleft()
    for v in E[u]:
        if dis[v] == -1:
            dis[v] = dis[u] + 1
            q.append(v)

dis[s] = dis[e] = -1
m = dis.index(max(dis))
ans += dis[m]
print(ans)
print(s + 1, e + 1, m + 1)