import os
import sys
from io import BytesIO, IOBase

# region fastio
BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
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

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

############# Importing modules and stuffs we require  ######################################################

try:
        import sys
        from functools import lru_cache, cmp_to_key, reduce
        from heapq import merge, heapify, heappop, heappush
        from math import *
        from collections import defaultdict as dd, deque, Counter as Cntr
        from itertools import combinations as comb, permutations as perm
        from bisect import bisect_left as bl, bisect_right as br, bisect, insort
        from time import perf_counter
        from fractions import Fraction
        import copy
        from copy import deepcopy
        import time
        from decimal import *
        starttime = time.time()
        mod = int(pow(10, 9) + 7)
        mod2 = 998244353

        def data(): return sys.stdin.readline()
        def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
        def L(): return list(sp())
        def sl(): return list(ssp())
        def sp(): return map(int, data().split())
        def ssp(): return map(str, data().split())
        def l1d(n, val=0): return [val for i in range(n)]
        def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
        def A2(n,m): return [[0]*m for i in range(n)]
        def A(n):return [0]*n

        # from sys import stdin
        # input = stdin.buffer.readline
        # I = lambda : list(map(int,input().split()))
        # import sys
        # input=sys.stdin.readline

        import random
        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
except:
        pass
rr = range

############# Importing modules and stuffs we require  ######################################################
n = L()[0]
A = [L() for i in range(n-1)]
g = [set() for i in range(n+1)]
for x,y in A:
    g[x].add(y)
    g[y].add(x)
rem = set([i for i in range(1,n+1)])
for i in range(n//2):
    u = 0
    for i in range(1,n+1):
        if len(g[i])==1:
            u = i
            break
    v = -1
    for i in range(u+1,n+1):
        if len(g[i])==1:
            v = i
            break
    
    print("?",u,v,flush=True)
    z = L()[0]
    if z in [u,v]:
        print("!",z,flush=True)
        exit()
    else:
        for ele in g[u]:
            g[ele].remove(u)
        g[u]=set()
        for ele in g[v]:
            g[ele].remove(v)
        g[v]=set()
        rem.remove(u)
        rem.remove(v)
else:
    for ele in rem:
        print("!",ele,flush=True)
        exit()