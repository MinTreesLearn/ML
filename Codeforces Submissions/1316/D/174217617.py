from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from math import inf, sqrt, ceil, log2
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
from typing import List
from bisect import bisect_left, bisect_right
import sys
import string
input=lambda:sys.stdin.buffer.readline()
mis=lambda:map(int,input().split())
ii=lambda:int(input())

N = ii()
grid = [[[-1,-1] for _ in range(N)] for _ in range(N)]
for i in range(N):
    row = list(mis())
    for j in range(N):
        if row[j*2] == -1 and row[j*2+1] == -1:
            grid[i][j] = [-1, -1]
        else:
            grid[i][j] = [row[j*2]-1, row[j*2+1]-1]

visited = [[None] * N for _ in range(N)]

DIRS = [(0,1, 'R'), (1,0, 'D'), (-1,0, 'U'), (0, -1, 'L')]
DIRS_p = {(0,1):'R', (1,0):'D', (-1,0):'U', (0, -1):'L'}
def dfs1(i, j, parent):
    if parent == [-1, -1]:
        count = 0
        for DIR in DIRS:
            ni, nj = DIR[0]+i, DIR[1]+j
            if not(0<=ni<N and 0<=nj<N):
                continue
            if not visited[ni][nj] and grid[ni][nj] == [-1,-1]:
                count += 1
                visited[i][j] = DIR[2]
                dfs1(ni, nj, [i, j])
        if count == 0:
            return False
    else:
        visited[i][j] = DIRS_p[(parent[0]-i, parent[1]-j)]
        for DIR in DIRS:
            ni, nj = DIR[0]+i, DIR[1]+j
            if not(0<=ni<N and 0<=nj<N):
                continue
            if not visited[ni][nj] and grid[ni][nj] == [-1,-1]:
                dfs1(ni, nj, [i, j])
    return True

def bfs1(i, j):
    pq = deque()
    count = 0
    for DIR in DIRS:
        ni, nj = DIR[0]+i, DIR[1]+j
        if not(0<= ni<N and 0<= nj < N):
            continue
        if not visited[ni][nj] and grid[ni][nj] == [-1,-1]:
            count += 1
            visited[i][j] = DIR[2]
            break
    if count == 0:
        return False

    pq.append((i,j))
    while pq:
        x, y = pq.popleft()
        for DIR in DIRS:
            ni, nj = DIR[0]+x, DIR[1]+y
            if not(0 <= ni < N and 0 <= nj < N):
                continue
            if not visited[ni][nj] and grid[ni][nj] == [-1, -1]:
                visited[ni][nj] = DIRS_p[(x-ni, y-nj)]
                pq.append((ni,nj))

    return True 

def dfs2(i, j, x, y):
    if i==x and j==y:
        visited[i][j] = 'X'
    for DIR in DIRS:
        ni, nj = DIR[0]+i, DIR[1]+j
        if not(0<=ni<N and 0<=nj<N):
            continue
        if not visited[ni][nj] and grid[ni][nj] == [x, y]:
            visited[ni][nj] = DIRS_p[(i-ni, j-nj)]
            dfs2(ni, nj, x, y)

def bfs2(i, j):
    visited[i][j] = 'X'
    pq = deque([[i, j]])
    while pq:
        x, y = pq.popleft()
        for DIR in DIRS:
            ni, nj = DIR[0]+x, DIR[1]+y
            if not(0 <= ni < N and 0 <= nj < N):
                continue
            if not visited[ni][nj] and grid[ni][nj] == [i, j]:
                visited[ni][nj] = DIRS_p[(x-ni, y-nj)]
                pq.append((ni, nj))


for i in range(N):
    for j in range(N):
        if visited[i][j]:
            continue
        if grid[i][j] == [-1, -1]:
            if not bfs1(i, j):
                print("INVALID")
                exit(0)
        else:
            x, y = grid[i][j][0], grid[i][j][1]
            if visited[x][y] or grid[x][y] != [x,y]:
                print("INVALID")
                exit(0)
            bfs2(x, y)
            if not visited[i][j]:
                print("INVALID")
                exit(0)

print("VALID")
for i in range(N):
    print("".join(visited[i]))




