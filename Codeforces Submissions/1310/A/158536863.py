import copy
import gc
import itertools
from array import array
from fractions import Fraction
import heapq
import math
import operator
import os, sys
import profile
import cProfile
import random
import re
import string
from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, Counter
from functools import reduce, lru_cache
from io import IOBase, BytesIO
from itertools import count, groupby, accumulate, permutations, combinations_with_replacement, product
from math import gcd
from operator import xor, add
from typing import List

# region fastio
BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._file = file
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


# print = lambda d: sys.stdout.write(str(d)+"\n")
def read_int_list(): return list(map(int, input().split()))
def read_int_tuple(): return tuple(map(int, input().split()))
def read_int(): return int(input())


# endregion

### CODE HERE

# f = open('inputs', 'r')
# def input(): return f.readline().rstrip("\r\n")

def solve(n, a, t):
    nums = defaultdict(list)
    for x, d in zip(a, t):
        nums[x].append(d)
    xs = sorted(nums)
    candis, cur, res = [], 0, 0
    for x in xs:
        for c in nums[x]:
            heapq.heappush(candis, -c)
            cur += c
        while True:
            stay = -heapq.heappop(candis)
            cur -= stay
            res += cur
            x += 1
            if x in nums or len(candis) == 0:
                break
    return res

def main():
    for _ in range(1):
        n = read_int()
        a = read_int_list()
        t = read_int_list()
        print(solve(n, a, t))

if __name__ == "__main__":
    main()
# cProfile.run("main()")
