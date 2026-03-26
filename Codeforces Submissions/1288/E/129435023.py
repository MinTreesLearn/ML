import os, sys
from io import BytesIO, IOBase
from math import log2, ceil, sqrt, gcd
from _collections import deque
import heapq as hp
from bisect import bisect_left, bisect_right
from math import cos, sin
from itertools import permutations
from operator import itemgetter

# sys.setrecursionlimit(2*10**5+10000)
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


def update(i, vl, x):
    i += x
    tree[i] += vl
    while i:
        tree[i >> 1] = tree[i] + tree[i ^ 1]
        i >>= 1


def query(l, r, x):
    l += x
    r += x
    ans = 0
    while l < r:
        if l & 1:
            ans += tree[l]
            l += 1
        if r & 1:
            r -= 1
            ans += tree[r]
        l >>= 1
        r >>= 1
    return ans


n, m = map(int, input().split())
a = list(map(int, input().split()))
tree = [0] * (2 * n + 5)
ans = [[i, i] for i in range(n + 1)]

for i in a:
    ans[i][0] = 1
    if tree[i + n + 1] == 0:
        x = query(i, n + 1, n + 1)
        ans[i][1] = x + i
        update(i, 1, n + 1)
tree = [0] * (2 * m + 5)
v = [-1] * (n + 1)
for i, vl in enumerate(a):
    if v[vl] == -1:
        v[vl] = i
        update(i, 1, m)
    else:
        x = query(v[vl], i, m)
        ans[vl][1] = max(ans[vl][1], x)
        update(v[vl], -1, m)
        update(i, 1, m)
        v[vl] = i
ct = n
for i in range(n, 0, -1):
    if v[i] == -1:
        ans[i][1] = max(ans[i][1], ct)
        ct -= 1
ck = []
for i in range(1, n + 1):
    if v[i] != -1:
        ck.append([v[i], i])
ck.sort()
for vl, i in ck:
    ans[i][1] = max(ans[i][1], ct)
    ct -= 1
for i in range(1, n + 1):
    print(*ans[i])
