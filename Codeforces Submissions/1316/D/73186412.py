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
created by shhuan at 2020/3/13 21:15

"""


def check(x, y, N):
    return 1 <= x <= N and 1 <= y <= N


def dfs(x, y, d, marks, X, Y, N):
    if not check(x, y, N) or marks[x][y] != '':
        return
    marks[x][y] = d
    if x+1 <= N and X[x][y] == X[x+1][y] and Y[x][y] == Y[x+1][y]:
        dfs(x+1, y, 'U', marks, X, Y, N)
    if x-1 > 0 and X[x][y] == X[x-1][y] and Y[x][y] == Y[x-1][y]:
        dfs(x-1, y, 'D', marks, X, Y, N)
    if y+1 <= N and X[x][y] == X[x][y+1] and Y[x][y] == Y[x][y+1]:
        dfs(x, y+1, 'L', marks, X, Y, N)
    if y-1 > 0 and X[x][y] == X[x][y-1] and Y[x][y] == Y[x][y-1]:
        dfs(x, y-1, 'R', marks, X, Y, N)


def dfs2(x, y, d, marks, X, Y, N):
    marks[x][y] = d
    q = [(x, y)]
    vx, vy = X[x][y], Y[x][y]
    while q:
        x, y= q.pop()
        for nx, ny, nd in [(x+1, y, 'U'), (x-1, y, 'D'), (x, y+1, 'L'), (x, y-1, 'R')]:
            if check(nx, ny, N) and X[nx][ny] == vx and Y[nx][ny] == vy and marks[nx][ny] == '':
                marks[nx][ny] = nd
                q.append((nx, ny))


def connect(x1, y1, x2, y2, d1, d2, marks, X, Y, N):
    if not check(x1, y1, N) or not check(x2, y2, N):
        return False

    if X[x2][y2] == -1:
        marks[x1][y1] = d1
        if marks[x2][y2] == '':
            marks[x2][y2] = d2
        return True
    return False


def solve(N, X, Y):
    marks = [['' for _ in range(N+2)] for _ in range(N+2)]
    for r in range(N+2):
        marks[r][0] = '#'
        marks[r][N+1] = '#'
        marks[0][r] = '#'
        marks[N+1][r] = '#'

    for r in range(1, N+1):
        for c in range(1, N+1):
            if X[r][c] == -1:
                res = marks[r][c] != ''
                if not res:
                    res = connect(r, c, r+1, c, 'D', 'U', marks, X, Y, N)
                if not res:
                    res = connect(r, c, r, c+1, 'R', 'L', marks, X, Y, N)
                if not res:
                    res = connect(r, c, r-1, c, 'U', 'D', marks, X, Y, N)
                if not res:
                    res = connect(r, c, r, c-1, 'L', 'R', marks, X, Y, N)
                if not res:
                    return 'INVALID'
            elif X[r][c] == r and Y[r][c] == c:
                dfs2(r, c, 'X', marks, X, Y, N)

    for r in range(1, N+1):
        for c in range(1, N+1):
            if marks[r][c] == '':
                return 'INVALID'

    ans = ['VALID']
    for r in range(1, N+1):
        row = ''.join([marks[r][c] for c in range(1, N+1)])
        ans.append(row)

    return '\n'.join(ans)


def test():
    N = 1000
    X = [[1000 for _ in range(N + 2)] for _ in range(N + 2)]
    Y = [[1000 for _ in range(N + 2)] for _ in range(N + 2)]
    solve(N, X, Y)

# test()

N = int(input())
X = [[0 for _ in range(N+2)] for _ in range(N+2)]
Y = [[0 for _ in range(N+2)] for _ in range(N+2)]
for r in range(1, N+1):
    cs = [int(x) for x in input().split()]
    for c in range(1, N+1):
        X[r][c] = cs[(c-1) * 2]
        Y[r][c] = cs[(c-1) * 2 + 1]

print(solve(N, X, Y))