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
 

import math


def solve():
    n, h, l, r = read_ints()
    nums = read_list()

    dp = [-math.inf]*h
    dp[nums[0]] = 1 if l<=nums[0]<=r else 0
    dp[nums[0]-1] = 1 if l<=nums[0]-1<=r else 0
    for i in range(1, n):
        tmp_dp = [-math.inf]*h
        for j, v in enumerate(dp):
            if v==-math.inf:
                continue

            idx = (j+nums[i])%h
            tmp = v+1 if l <= idx <= r else v
            if tmp > tmp_dp[idx]:
                tmp_dp[idx] = tmp

            idx = (j+nums[i]-1)%h
            tmp = v+1 if l <= idx <= r else v
            if tmp > tmp_dp[idx]:
                tmp_dp[idx] = tmp
        
        dp = tmp_dp
    
    print(max(dp))


solve()