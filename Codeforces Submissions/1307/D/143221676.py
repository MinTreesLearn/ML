

import math
from bisect import bisect_right
from bisect import bisect_left
import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType
from collections import defaultdict
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
sys.setrecursionlimit(10**5)


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

from collections import deque

n,m,k=map(int,input().split())
a=list(map(int,input().split()))
adj=[[] for i in range(n+1)]
for j in range(m):
    x,y=map(int,input().split())
    adj[x].append(y)
    adj[y].append(x)

dis1=[float("inf") for i in range(n+1)]
dis2=[float("inf") for i in range(n+1)]
q=deque([1])
dis1[1]=0
while(q):
    curr=q.popleft()
    for j in adj[curr]:
        if(dis1[j]==float("inf")):
            q.append(j)
            dis1[j]=dis1[curr]+1

q=deque([n])
dis2[n]=0
while(q):
    curr=q.popleft()
    for j in adj[curr]:
        if(dis2[j]==float("inf")):
            q.append(j)
            dis2[j]=dis2[curr]+1

s=dis1[n]
res1=[]
res2=[]
for j in a:
    res1.append([dis1[j],j])

res1.sort()
curr=dis2[res1[-1][1]]
m=0
j=k-2
while(j>=0):
    m=max(m,res1[j][0]+curr+1)
    curr=max(curr,dis2[res1[j][1]])
    j+=-1


s=min(s,m)
print(s)
























