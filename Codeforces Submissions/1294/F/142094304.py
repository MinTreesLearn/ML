from bisect import bisect_right
from collections import defaultdict
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

sys.setrecursionlimit(3*10**5)


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
def dfs(u,p):
    curr=u
    m=0
    for j in adj[u]:
        if(j!=p):
            q=yield dfs(j,u)
            if((size[j]+1)>m):
                m=size[j]+1
                curr=q
    size[u]=m
    val[u]=curr
    yield curr

@bootstrap
def dfs1(u,p):
    global curr
    global c
    size[u]=0
    q=u
    for j in adj[u]:
        if(j!=p):
            r=yield dfs1(j,u)
            if(val[j]!=b):
                if(size[j]+1>size[u]):
                    size[u]=size[j]+1
                    q=r
    if(curr<=size[u]):
        curr=size[u]
        c=q
    yield q






n=int(input())
adj=[[] for i in range(n+1)]
for _ in range(n-1):
    u,v=map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)

size=[0 for i in range(n+1)]
val=[i for i in range(n+1)]
a=dfs(1,0)
size=[0 for i in range(n+1)]
b=dfs(a,0)
dm=size[a]
curr=0
c=-1
dfs1(a,0)
if(dm==n-1 or c==-1):
    for i in range(1,4):
        if(i!=a and i!=b):
            c=i
            break
print(dm+curr)
print(a,b,c)

    


