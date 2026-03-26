from math import sqrt
import sys
from functools import reduce
from collections import deque


import io
import os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def input():
    return sys.stdin.readline().strip()


def iinput():
    return int(input())


def tinput():
    return input().split()


def rinput():
    return map(int, tinput())


def rlinput():
    return list(rinput())


mod = int(1e9)+7


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


# ----------------------------------------------------

if __name__ == "__main__":
    n = iinput()
    mat = [[[-1, -1] for i in range(n)]for i in range(n)]
    ans = [['' for i in range(n)]for i in range(n)]
    stack = deque()
    for i in range(n):
        temp = rlinput()
        for j in range(n):
            mat[i][j][0] = temp[2*j]
            mat[i][j][1] = temp[2*j+1]
            if (temp[2*j], temp[2*j+1]) == (i+1, j+1):
                ans[i][j] = 'X'
                stack.append((i, j))

    # Part 2
    while stack:
        state = stack.pop()
        i, j = state
        if i < n-1 and ans[i+1][j] == '':
            if mat[i+1][j] == mat[i][j]:
                ans[i+1][j] = 'U'
                stack.append((i+1, j))
        if j < n-1 and ans[i][j+1] == '':
            if mat[i][j+1] == mat[i][j]:
                ans[i][j+1] = 'L'
                stack.append((i, j+1))
        if i > 0 and ans[i-1][j] == '':
            if mat[i-1][j] == mat[i][j]:
                ans[i-1][j] = 'D'
                stack.append((i-1, j))
        if j > 0 and ans[i][j-1] == '':
            if mat[i][j-1] == mat[i][j]:
                ans[i][j-1] = 'R'
                stack.append((i, j-1))

    for i in range(n):
        for j in range(n):
            if mat[i][j] == [-1, -1]:
                if i < n-1 and mat[i+1][j] == [-1, -1]:
                    ans[i][j] = 'D'
                    continue
                if j < n-1 and mat[i][j+1] == [-1, -1]:
                    ans[i][j] = 'R'
                    continue
                if i > 0 and mat[i-1][j] == [-1, -1]:
                    ans[i][j] = 'U'
                    continue
                if j > 0 and mat[i][j-1] == [-1, -1]:
                    ans[i][j] = 'L'
                    continue

    flag = True
    for i in ans:
        for j in i:
            if j == '':
                print('INVALID')
                sys.exit()

    print('VALID')
    for i in ans:
        print(''.join(i))
