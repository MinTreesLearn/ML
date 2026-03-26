import re
import functools
import random
import sys
import os
import math
from collections import Counter, defaultdict, deque
from functools import lru_cache, reduce
from itertools import accumulate, combinations, permutations
from heapq import nsmallest, nlargest, heappushpop, heapify, heappop, heappush
from io import BytesIO, IOBase
from copy import deepcopy
import threading
from typing import *
from operator import add, xor, mul, ior, iand, itemgetter
import bisect
BUFSIZE = 4096
inf = float('inf')

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

sys.stdin = IOWrapper(sys.stdin)
sys.stdout = IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def I():
    return input()

def II():
    return int(input())

def MII():
    return map(int, input().split())

def LI():
    return list(input().split())

def LII():
    return list(map(int, input().split()))

def GMI():
    return map(lambda x: int(x) - 1, input().split())

def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

from types import GeneratorType
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

n = II()
nums = LII()

ans_left = [0] * n
stack_left = [[-1, 0]]
for i in range(n):
    num = nums[i]
    while stack_left[-1][1] >= num:
        stack_left.pop()
    ans_left[i] = (i + 1) * num if len(stack_left) == 1 else (i - stack_left[-1][0]) * num + ans_left[stack_left[-1][0]]
    stack_left.append([i, num])

ans_right = [0] * n
stack_right = [[n, 0]]
for i in range(n-1, -1, -1):
    num = nums[i]
    while stack_right[-1][1] >= num:
        stack_right.pop()
    ans_right[i] = (n - i) * num if len(stack_right) == 1 else (stack_right[-1][0] - i) * num + ans_right[stack_right[-1][0]]
    stack_right.append([i, num])

res, idx = 0, 0
for i in range(n):
    if ans_left[i] + ans_right[i] - nums[i] > res:
        res = ans_left[i] + ans_right[i] - nums[i]
        idx = i

final = [0] * n
final[idx] = nums[idx]

tmp = nums[idx]
for j in range(idx-1, -1, -1):
    tmp = min(tmp, nums[j])
    final[j] = tmp

tmp = nums[idx]
for j in range(idx+1, n):
    tmp = min(tmp, nums[j])
    final[j] = tmp

print(*final)