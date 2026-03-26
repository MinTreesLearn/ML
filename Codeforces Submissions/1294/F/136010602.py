import os, sys
from io import BytesIO, IOBase
from math import log2, ceil, sqrt, gcd
from _collections import deque
import heapq as hp
from bisect import bisect_left, bisect_right
from math import cos, sin
from itertools import permutations
from operator import itemgetter

sys.setrecursionlimit(5 * 10 ** 4)
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

pi = 3.1415926535
mod = 998244353

from types import GeneratorType


def iterative(f, stack=[]):
    def wrapped_func(*args, **kwargs):
        if stack: return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
                continue
            stack.pop()
            if not stack: break
            to = stack[-1].send(to)
        return to

    return wrapped_func

@iterative
def dfs(x, y):
    for i in a[x]:
        if i != y:
            yield dfs(i, x)
    if len(a[x]) == 1:
        dp[x].append([0, x])
        dp[y].append([1, x])
    else:
        dp[x].sort(key=itemgetter(0), reverse=True)
        while len(dp[x]) > 3:
            dp[x].pop()
        dp[y].append([dp[x][0][0] + 1, dp[x][0][1]])
    yield


@iterative
def dfs2(x, y):
    if len(dp[x]) == 3:
        ct = 0
        for i, j in dp[x]:
            ct += i
        ct += 1
        if ct > tot[0]:
            pt[0] = x
            tot[0] = ct
            ans.clear()
            for i, j in dp[x]:
                ans.append(j)
    elif len(dp[x]) == 2:
        ct = 0
        for i,j in dp[x]:
            ct+=i
            if j==x:
                ct=-1
                break
        if ct!=-1:
            ct+=1
            if ct > tot[0]:
                pt[0] = x
                tot[0] = ct
                ans.clear()
                for i, j in dp[x]:
                    ans.append(j)
                ans.append(x)

    for i in a[x]:
        if i != y:
            for j1, j2 in dp[x]:
                if [j1 - 1, j2] not in dp[i]:
                    dp[i].append([j1 + 1, j2])
                    break
            dp[i].sort(key=itemgetter(0), reverse=True)
            while len(dp[i]) > 3:
                dp[i].pop()
            yield dfs2(i, x)
    yield

n = int(input())
a = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = map(int, input().split())
    a[x].append(y)
    a[y].append(x)
dp = [[] for _ in range(n + 1)]
dfs(1, 0)
tot = [0]
ans = []
pt = [-1]
dfs2(1, 0)
print(tot[0] - 1)
print(*ans)
