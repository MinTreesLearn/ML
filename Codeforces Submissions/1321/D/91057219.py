# ------------------- fast io --------------------
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
 
# ------------------- fast io --------------------
from collections import deque,defaultdict
n,m=map(int,input().split());rev=[[] for s in range(n)]
for s in range(m):
    u,v=map(int,input().split())
    u-=1;v-=1
    rev[v].append(u)
k=int(input());vals=[int(i)-1 for i in input().split()]
queue=deque([vals[-1]]);pos=defaultdict(list);pos[vals[-1]]=[0,set([])]
while len(queue)>0:
    v0=queue.popleft()
    for s in range(len(rev[v0])):
        node=rev[v0][s]
        if len(pos[node])==0:
            pos[node]=[pos[v0][0]+1,set([v0])]
            queue.append(node)
        else:
            if pos[v0][0]+1<pos[node][0]:
                pos[node]=[pos[v0][0]+1,set([v0])]
            elif pos[v0][0]+1==pos[node][0]:
                pos[node][1].add(v0)
v1=[pos[k]+[k] for k in pos.keys()]
v1.sort(key= lambda x: x[0])
maxy=0;minny=0
for s in range(k-1):
    if not(vals[s+1] in pos[vals[s]][1]):
        maxy+=1;minny+=1
    elif vals[s+1] in pos[vals[s]][1] and len(pos[vals[s]][1])>=2:
        maxy+=1
print(minny,maxy)