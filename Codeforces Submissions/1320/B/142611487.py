def I(): return input().strip()
def II(): return int(input().strip())
def LI(): return [*map(int, input().strip().split())]
import sys, os, copy, string, math, time, functools, fractions
input = sys.stdin.readline
from io import BytesIO, IOBase
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter, OrderedDict
from itertools import permutations, chain, combinations, groupby
from operator import itemgetter
from types import GeneratorType  # for recursion
from typing import Iterable, TypeVar, Union  # for sorted set

# template starts


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


# template ends


def main():
    n, m = LI()
    g, gr = defaultdict(list), defaultdict(list)
    for i in range(m):
        u, v = LI()
        u, v = u - 1, v - 1
        g[u].append(v)
        gr[v].append(u)
    k = II()
    p = [x - 1 for x in LI()]

    vis = [False] * n
    dis = [0] * n
    que = deque([p[-1]])
    vis[p[-1]] = True
    while que:
        pop = que.popleft()
        for vrt in gr[pop]:
            if not vis[vrt]:
                vis[vrt] = True
                dis[vrt] = dis[pop] + 1
                que.append(vrt)

    men, mex = 0, 0
    for i in range(k - 1):
        if dis[p[i]] != dis[p[i + 1]] + 1:
            men += 1
            mex += 1
            continue
        cnt = 0
        for vrt in g[p[i]]:
            if dis[p[i]] == dis[vrt] + 1:
                cnt += 1
        if cnt > 1:
            mex += 1
    print(men, mex)


for _ in range(1):
    main()

