import os
import sys
from io import BytesIO, IOBase
from collections import Counter, defaultdict
import math
import heapq
import bisect
import collections
def ceil(a, b):
    return (a + b - 1) // b
BUFSIZE = 8192
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
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
get = lambda: sys.stdin.readline().rstrip("\r\n")
MOD = 1000000007
def v():
    return list()
# for _ in range(int(get())):
# n=int(get())
# l=list(map(int,get().split()))
# = map(int,get().split())
###########################################################################
###########################################################################
n,k = map(int,get().split())
l=[]
for i in range(n):
    s=get()
    l.append(s)
temp=set(l)
ans=0
for i in range(n):
    for j in range(i+1,n):
        c=""
        for t in range(k):
            if l[i][t]==l[j][t]:
                c+=l[i][t]
            else:
                s1=["S","T","E"]
                for f in s1:
                    if f!=l[i][t] and f!=l[j][t]:
                        c+=f
        if c in temp:
            ans+=1

print(ans//3)




















