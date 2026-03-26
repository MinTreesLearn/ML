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
# sys.setrecursionlimit(10000000)
inf = float('inf')
eps = 10 ** (-15)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

class BIT:
    def __init__(self, N):
        self.N = N
        self.bit = [0] * (N + 1)
        self.b = 1 << N.bit_length() - 1

    def add(self, a, w):
        x = a + 1
        while(x <= self.N):
            self.bit[x] += w
            x += x & -x

    def get(self, a):
        ret, x = 0, a
        while(x > 0):
            ret += self.bit[x]
            x -= x & -x
        return ret

    def cum(self, l, r):
        return self.get(r) - self.get(l)

    def lowerbound(self, w):
        if w <= 0:
            return -1
        x = 0
        k = self.b
        while k > 0:
            if x + k <= self.N and self.bit[x + k] < w:
                w -= self.bit[x + k]
                x += k
            k //= 2
        return x

N = getN()
S = [ord(s) - ord('a') for s in input()]
S = [[S[i], i] for i in range(N)]
S.sort(key = lambda i:i[1], reverse = True)
S.sort(key = lambda i:i[0], reverse = True)

seg = [BIT(N) for i in range(27)]
ans = [0] * N
for _, ind in S:
    c = 1
    while seg[c].get(ind) >= 1:
        c += 1
    ans[ind] = c
    seg[c].add(ind, 1)

print(max(ans))
print(*ans)