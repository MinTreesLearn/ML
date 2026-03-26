import functools
import math
import random
from collections import defaultdict,deque
from heapq import  heapify,heappop,heappush
import bisect
from collections import Counter
import collections
from functools import lru_cache
import time
from typing import List
from math import log
from  random import  randint,seed
from time import time
import os,sys
from io import BytesIO, IOBase

# Fast IO Region
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

n,a,t=int(input()),list(map(int,input().split())),list(map(int,input().split()))
# n,a,t=5,[3,7,9,7,8],[5,2,5,7,5]
dt=defaultdict(list)
for i in range(n):
    dt[a[i]].append(t[i])

data=sorted(dt.items(),key=lambda x:x[0])
# print(data)
ans,cur,sum,n=0,[],0,len(data)
for i,(x,lst) in enumerate(data):
    for cost in lst:
        heappush(cur,-cost)
        sum+=cost
    top=heappop(cur)
    sum-=-top
    x+=1
    while i<n-1 and x<data[i+1][0] and cur:
        ans+=sum
        x+=1
        sum-=-heappop(cur)
    ans+=sum
while cur:
    sum-=-heappop(cur)
    ans += sum
print(ans)