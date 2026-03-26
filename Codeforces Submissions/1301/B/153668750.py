import os
import sys
from io import BytesIO, IOBase

# import string
# characters = string.ascii_lowercase
# digits = string.digits
# sys.setrecursionlimit(int(1e6))
# dir = [-1,0,1,0,-1]
# moves = 'NESW'
inf = float('inf')
from functools import cmp_to_key
from collections import defaultdict as dd
from collections import Counter, deque
from heapq import *
import math
from math import floor, ceil, sqrt
def geti(): return map(int, input().strip().split())
def getl(): return list(map(int, input().strip().split()))
def getis(): return map(str, input().strip().split())
def getls(): return list(map(str, input().strip().split()))
def gets(): return input().strip()
def geta(): return int(input())
def print_s(s): stdout.write(s+'\n')


def solve():
    for _ in range(geta()):
        n = geta()
        a = getl()
        need = []
        ans = 0
        for i in range(n):
            if a[i] != -1 and ((i and a[i-1] == -1) or (i+1 < n and a[i+1] == -1)):
                need.append(a[i])
            if i and a[i] != -1 and a[i-1] != -1:
                ans = max(ans, abs(a[i] - a[i-1]))
        # print(need)
        if not need:
            print(0, 0)
            continue
        start = 0
        end = int(1e9)
        now = end
        k = -1
        while start <= end:
            mid = (start + end) // 2
            left = max(0, need[0] - mid)
            right = min(need[0] + mid, int(1e9))
            ok = True
            # print(mid, left, right)
            for i in need:
                l = max(0, i - mid)
                r = min(i + mid, int(1e9))
                left = max(left, l)
                right = min(right, r)
                if left > right:
                    ok = False
                    break
            if not ok:
                start = mid + 1
            else:
                end = mid - 1
                now = mid
                k = left
                # print('yes')
        if now == int(1e9):
            print(ans, k)
        else:
            print(max(ans, now), k)






# Fast IO region
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

if __name__=='__main__':
    solve()
