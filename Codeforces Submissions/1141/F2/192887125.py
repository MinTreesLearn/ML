#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
'''
@File    :   F_2_Same_Sum_Blocks_Hard.py
@Time    :   2023/02/08 23:31:26
@Author  :   @bvf
'''

import sys
import os
from io import BytesIO, IOBase
from types import GeneratorType

BUFSIZE = 4096

class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, **kwargs):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b'\n') + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')

def debug(func):
    def wrapper(*args, **kwargs):
        res = func(*args, **kwargs)
        print('----------------')
        return res
    return wrapper

# 'return->yield','dfs()->yield dfs()'
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def I():
    return input()

def II():
    return int(input())

def MI():
    return map(int, input().split())

def LI():
    return list(input().split())

def LII():
    return list(map(int, input().split()))

def GMI():
    return map(lambda x: int(x) - 1, input().split())

def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

# ------------------------------FastIO---------------------------------
# from typing import *
# from bisect import bisect_left, bisect_right
# from copy import deepcopy, copy
# from math import comb, gcd, factorial, log, log2
from collections import Counter, defaultdict, deque
# from itertools import accumulate, combinations, permutations, groupby
# from heapq import nsmallest, nlargest, heapify, heappop, heappush, heapreplace
# from functools import lru_cache, reduce
# from sortedcontainers import SortedList, SortedSet

MOD = int(1e9 + 7)
M9D = int(998244353)
INF = int(1e20)
# -------------------------------@bvf----------------------------------

n = II()
a = LII()

d = defaultdict(list)
for i in range(n):
    tt = 0
    for j in range(i,n):
        tt += a[j]
        d[tt].append((i+1,j+1))

res = 0
ret = []
for v in d.values():
    r = -1
    cnt = 0
    o = []
    v.sort(key= lambda x: x[1])
    for s,t in v:
        if s>r:
            r = t
            cnt += 1
            o.append((s,t))
    if cnt>res:
        res = cnt
        ret = o.copy()

print(res)
for x,y in ret:
    print(x,y)
