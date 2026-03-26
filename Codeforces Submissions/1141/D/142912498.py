import os
import sys
from io import BytesIO, IOBase
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
from math import *
from collections import defaultdict
def solve():
    n=int(input())
    a=input()
    b=input()
    dl=defaultdict(list)
    dr=defaultdict(list)
    left=[]
    right=[]
    ans=[]
    for i in range(n):
        dl[a[i]].append(i+1)
        dr[b[i]].append(i+1)
    for i in range(97,123):
        char=chr(i)
        for j in range(min(len(dl[char]),len(dr[char]))):
            ans.append([dl[char][-1],dr[char][-1]])
            dl[char].pop()
            dr[char].pop()
        if len(dl[char])>0:
            for j in dl[char]:
                left.append(j)
        else:
            for j in dr[char]:
                right.append(j)
    for j in range(min(len(left),len(dr['?']))):
        ans.append([left[-1],dr['?'][-1]])
        left.pop()
        dr['?'].pop()
    for j in range(min(len(right),len(dl['?']))):
        ans.append([dl['?'][-1],right[-1]])
        right.pop()
        dl['?'].pop()
    char='?'
    for i in range(min(len(dl[char]),len(dr[char]))):
        ans.append([dl[char][-1],dr[char][-1]])
        dl[char].pop()
        dr[char].pop()
    print(len(ans))
    for x,y in ans:
        print(x,y)
for _ in range(1):
    solve()