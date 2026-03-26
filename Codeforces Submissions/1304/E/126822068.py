import os
import sys
from io import BytesIO, IOBase
# region fastio
 
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
print = lambda s: sys.stdout.write(s + "\n")

n = int(input())
G = [[] for _ in range(n)]
for _ in range(n-1):
    u,v = map(int,input().split())
    G[u-1].append(v-1)
    G[v-1].append(u-1)

depth = []
euler = []
ref = [-1]*n
log = []

root = 0
stk = [(root,-1,-1)]
while stk:
    node,par,idx = stk.pop()
    if idx == -1:
        # unseen node
        if par != -1:
            depth.append(depth[ref[par]] + 1)
        else:
            depth.append(0)
        ref[node] = len(euler)
        euler.append(len(euler))
        log.append(node)
        idx += 1
    else:
        euler.append(euler[ref[node]])
        depth.append(depth[ref[node]])
        log.append(node)


    if idx < len(G[node]) and G[node][idx] == par:
        idx += 1

    if idx == len(G[node]):
        continue

    stk.append((node, par, idx+1))
    stk.append((G[node][idx], node, -1))

def sparse_table(x):
    sz = len(x)
    LOG = 0
    while 1<<(LOG+1) < sz+1:
        LOG += 1
     
    dp = [[None]*(LOG+1) for _ in range(sz)]
    for i in range(sz):
        dp[i][0] = x[i]
     
    for j in range(1,LOG+1):
        for i in range(sz):
            if i-1 + (1<<j)  >= sz:
                break
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1])
    return dp

dp = sparse_table(euler)
def lca(i,j):
    i,j = min(i,j),max(i,j)
    L = 0
    while 1<<(1+L) <= j-i+1:
        L += 1
    t = min(dp[i][L], dp[j+1 - (1<<L)][L])
    return log[t]

def dist(u,v):
    du = depth[ref[u]]
    dv = depth[ref[v]]
    dlca = depth[ref[lca(ref[u],ref[v])]]
    
    return du + dv - 2*dlca

for nq in range(int(input())):
    x,y,a,b,k = map(int,input().split())
    x -= 1
    y -= 1
    a -= 1
    b -= 1

    path1 = dist(a,b)
    if path1 <= k and (path1-k)%2 == 0:
        print("YES")
        continue

    path2 = dist(a,x) + dist(b,y) + 1
    if path2 <= k and (path2-k)%2 == 0:
        print("YES")
        continue

    path3 = dist(a,y) + dist(b,x) + 1
    if path3 <= k and (path3-k)%2 == 0:
        print("YES")
        continue

    print("NO")
    
