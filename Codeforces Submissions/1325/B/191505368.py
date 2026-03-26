# from collections import Counter, defaultdict, deque
import os
import sys
# from math import gcd, ceil, sqrt
# from bisect import bisect_left, bisect_right
# import math, bisect, heapq, random
# from functools import lru_cache, reduce, cmp_to_key
# from itertools import accumulate, combinations, permutations
from io import BytesIO, IOBase


inf = float('inf')
mod = 10**9 + 7

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
print = lambda *args, **kwargs: sys.stdout.write(" ".join(map(str, args)) + " " if kwargs.get("end") == " " else " ".join(map(str, args)) + " " if kwargs.get("end") == " " else " ".join(map(str, args)) + "\n")
ints = lambda: list(map(int, input().split()))
#------------------- fast io --------------------#

def solve():
    ints(); print(len(set(ints())))


for _ in range(int(input())): solve()