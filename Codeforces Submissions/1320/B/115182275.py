# Author : nitish420 --------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase

from collections import deque

def main():
    n,m=map(int,input().split())
    graph=[[] for _ in range(n+1)]
    for _ in range(m):
        u,v=map(int,input().split())
        graph[v].append(u)
    k=int(input())
    path=list(map(int,input().split()))

    start=path[0]
    end=path[-1]

    dist=[-1]*(n+1)
    dist[end]=0
    directCount=[0]*(n+1)
    queue=deque([end])
    vis=[0]*(n+1)
    vis[end]=1
    while queue:
        z=queue.popleft()
        for item in graph[z]:
            if vis[item]==0:
                vis[item]=1
                dist[item]=dist[z]+1
                queue.append(item)
                directCount[item]=1
            elif dist[item]==dist[z]+1:
                directCount[item]+=1
    # print(dist)
    mm,mx=0,0
    prev=dist[start]
    for i in range(1,k-1):
        z=path[i]
        if dist[z]==prev-1:
            if directCount[path[i-1]]>1:
                mx+=1
        else:
            mm+=1
        prev=dist[z]
    print(mm,mx+mm)

# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
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
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')



# endregion

if __name__ == '__main__':
    main()