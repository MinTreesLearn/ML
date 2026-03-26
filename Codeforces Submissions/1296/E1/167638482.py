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
#######################################
from collections import deque
n=int(input())
s=list(input())
l=[[s[i],i] for i in range(n)]
l.sort()
adj=[[] for i in range(n)]
v=[0]*n
for i in range(n):
    for j in range(i-1,-1,-1):
        if l[j][1]>l[i][1]:
            adj[l[j][1]].append(l[i][1])
            adj[l[i][1]].append(l[j][1])
ans="YES"
col=[0]*n
for x in range(n):
    if not v[x]:
        q=deque()
        q.append(x)
        v[x]=1      
        while len(q):
            cur=q.popleft()
            for i in adj[cur]:
                if not v[i]:
                    v[i]=1
                    col[i]=col[cur]^1
                    q.append(i)
                else:
                    if col[i]==col[cur]:
                        ans="NO"
                        break
    if ans=="NO":
        break
print(ans)
if ans=="YES":
    print(*col,sep='')
            
