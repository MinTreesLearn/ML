from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
import random
import copy
import threading
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
sys.setrecursionlimit(10 ** 6)


N = ii()
A = list(mis())
edges = defaultdict(list)
for _ in range(N-1):
    u, v = mis()
    edges[u].append(v)
    edges[v].append(u)

for i in range(N):
    if A[i] == 0:
        A[i] = -1

dp = [0] * N
ans = [0] * N
def dfs1(node, p = 0):
    dp[node-1] = A[node-1]
    
    for nei in edges[node]:
        if nei == p:
            continue 
        dfs1(nei, node)
        dp[node-1] += max(0, dp[nei-1])

def dfs2(node, p, maxp):
    ans[node-1] = maxp + dp[node-1]
    for nei in edges[node]:
        if nei == p:
            continue

        dfs2(nei, node, max(ans[node-1] - max(0, dp[nei-1]), 0))

#        if dp[nei-1] > 0:
#            newmaxp = dp[node-1] - dp[nei-1]
#            dfs2(nei, node, max(0, maxp + newmaxp))
#        else:
#            newmaxp = dp[node-1]
#            dfs2(nei, node, max(0, maxp + newmaxp))

def main():
    dfs1(1)
    dfs2(1, 0, 0)
    print(*ans)

if __name__ == "__main__":
    threading.stack_size(10**8)
    t = threading.Thread(target=main)
    t.start()
    t.join()
