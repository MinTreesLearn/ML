from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(10 ** 7)

N = ii()
S = input()

edges = defaultdict(list)
color = [-1] * N

def dfs(i, node_color):
    if color[i] == node_color:
        return 
    elif color[i] != -1 and color[i] ^ node_color:
        print("NO")
        exit(0)
    color[i] = node_color 
    for nei in edges[i]:
        dfs(nei, 1-node_color)

for i, c in enumerate(S):
    for j in range(i):
        if S[j] > c:
            edges[i].append(j)
            edges[j].append(i)

for i in range(N):
    if color[i] == -1:
        dfs(i, 0)

print("YES")
print("".join(map(str,color)))








    




