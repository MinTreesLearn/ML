from collections import defaultdict
from math import log2
from bisect import bisect_left

import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType

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








@bootstrap
def dfs(u,p,curr):

    global l
    cnt=1
    for j in adj[u]:
        if j!=p:
            rem=(curr+cnt)%l
            if rem==0:
                rem=l
            edge[d[(u,j)]]=rem
            yield dfs(j,u,rem)
            cnt+=1
    yield





n,k=map(int,input().split())
adj=[[] for i in range(n+1)]
tot=[0 for i in range(n+1)]
d=dict()
for j in range(n-1):
    u,v=map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)
    tot[u]+=1
    tot[v]+=1
    d[(u,v)]=j
    d[(v,u)]=j
tot=tot[1:]
tot.sort()

l=1
r=n-1
while(l<r):
    m=(l+r)//2
    if n-bisect_left(tot,m+1)>k:
        l=m+1
    else:
        r=m

cnt=[0 for i in range(n+1)]
edge=[-1 for i in range(n-1)]
dfs(1,0,0)
print(l)
print(*edge)






