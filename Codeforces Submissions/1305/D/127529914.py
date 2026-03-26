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



def ask(x, y):
    print('?', x, y, flush=True)
    return int(input())


n = int(input())
a = [set() for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = map(int, input().split())
    a[x].add(y)
    a[y].add(x)

ck=[]
for i in range(1,n+1):
    if len(a[i])==1:
        ck.append(i)

for _ in range(n // 2):

    x = ck.pop()
    y = ck.pop()
    # print(ck,x,y,dd)
    z = ask(x, y)
    if z == x:
        print('!', x, flush=True)
        exit()
    if z == y:
        print('!', y, flush=True)
        exit()

    for i in a[x]:
        a[i].remove(x)
        if len(a[i])==1:
            ck.append(i)
    for i in a[y]:
        a[i].remove(y)
        if len(a[i])==1:
            ck.append(i)

print('!', ck.pop(), flush=True)
