import os, sys
from io import BytesIO, IOBase
from math import log2, ceil, sqrt, gcd
from _collections import deque
import heapq as hp
from bisect import bisect_left, bisect_right
from math import cos, sin
from itertools import permutations

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

mod = (10 ** 9 + 7) ^ 1755654


def update(i, vl):
    i += n
    tree[i][0] += vl
    tree[i][1] += 1
    while i:
        tree[i >> 1][0] = tree[i][0] + tree[i ^ 1][0]
        tree[i >> 1][1] = tree[i][1] + tree[i ^ 1][1]
        i >>= 1


def query(l, r):
    l += n
    r += n
    ans = [0, 0]
    while l < r:
        if l & 1:
            ans[0] += tree[l][0]
            ans[1] += tree[l][1]
            l += 1
        if r & 1:
            r -= 1
            ans[0] += tree[r][0]
            ans[1] += tree[r][1]
        l >>= 1
        r >>= 1
    return ans


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = set(b)
d = dict()
id = 0
for i in sorted(s):
    d[i] = id
    id += 1
ck = [[i, d[j]] for i, j in zip(a, b)]
ck.sort()
tree = [[0, 0] for _ in range(2 * id + 1)]
n = id
ans = 0
for x, v in ck:
    tot, ct = query(0, v + 1)
    ans += x * ct - tot
    update(v, x)
print(ans)
