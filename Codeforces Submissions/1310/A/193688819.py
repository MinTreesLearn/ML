import math
import heapq
import bisect
import functools
import itertools
import collections
import os
import sys
from io import BytesIO, IOBase

MOD0 = 10 ** 9 + 7
MOD1 = 998244353
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
read_str = lambda: input().strip()
read_int = lambda: int(input())
read_ints = lambda: map(int, input().split())
read_list = lambda: list(map(int, input().split()))


def solve():
    n = read_int()
    a = read_list()
    b = read_list()

    nums, heap, ans, cur_sum = sorted(zip(a, b), reverse=True), [], 0, 0
    max_val, cur = nums[0][0], nums[-1][0]
    while cur <= max_val:
        while nums and nums[-1][0] == cur:
            _, tmp = nums.pop()
            heapq.heappush(heap, -tmp)
            cur_sum += tmp
        if cur == max_val and (not heap):
            break
        if heap:
            cur_sum += heapq.heappop(heap)
            ans += cur_sum
        cur += 1
        if cur > max_val:
            max_val = cur
        elif (not heap) and nums:
            cur = nums[-1][0]
            heap, cur_sum = [], 0

    print(ans)


solve()