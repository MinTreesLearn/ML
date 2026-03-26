from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
input=lambda:sys.stdin.readline().strip('\n')
mis=lambda:map(int,input().split())
ii=lambda:int(input())
#sys.setrecursionlimit(5*(10 ** 3))

T = ii()
for _ in range(T):
    S = input()
    T = input()
    N = len(S)
    M = len(T)

    nxt = [[N] * 26 for _ in range(N+2)]
    for i in reversed(range(N)):
        nxt[i] = nxt[i+1][:]
        nxt[i][ord(S[i]) - ord('a')] = i

    for mid in range(M):
        dp = [[N] * (M+1) for _ in range(M+1)]
        left = T[:mid]
        right = T[mid:]

        dp[0][0] = -1
        for i in range(len(left)+1):
            for j in range(len(right)+1):
                if i > 0:
                    dp[i][j] = min(dp[i][j], nxt[dp[i-1][j]+1][ord(left[i-1])-ord('a')])
                if j > 0:
                    dp[i][j] = min(dp[i][j], nxt[dp[i][j-1]+1][ord(right[j-1])-ord('a')])
        if dp[len(left)][len(right)] < N:
            print("YES")
            break
    else:
        print("NO")


