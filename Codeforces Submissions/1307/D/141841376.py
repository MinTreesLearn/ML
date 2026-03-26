import os
import sys
from collections import defaultdict,deque
from io import BytesIO, IOBase
# MOD = 998244353
# nmax = 5000

# fact = [1] * (nmax+1)
# for i in range(2, nmax+1):
#     fact[i] = fact[i-1] * i % MOD
    
# inv = [1] * (nmax+1)
# for i in range(2, nmax+1):
#     inv[i] = pow(fact[i], MOD-2, MOD)
 
 
# def C(n, m):
#     return fact[n] * inv[m] % MOD * inv[n-m] % MOD if 0 <= m <= n else 0
# from itertools import permutations
# from bisect import bisect_left
# d=[]
# for i in range(1,7):
#     def solve(j,p):
#         if j==i:
#             return d.append(p)
#         for el in [0,1]:
#             solve(j+1,10*p+el)
#     solve(0,0)
from collections import Counter
def main():
    from collections import defaultdict, deque
    def bfs(start, n):
        dist=[-1]*n
        q=deque()
        visited=set()
        q.append(start)
        temp=0
        while q:
            n=len(q)
            for _ in range(n):
                curr=q.popleft()
                if curr in visited:
                    continue
                dist[curr]=temp
                visited.add(curr)
                for node in graph[curr]:
                    if node not in visited:
                        q.append(node)
            temp+=1
        return dist
            
    n,m,k=map(int,input().split())
    sp=list(map(int,input().split()))

    sp=[el-1 for el in sp]
    graph=defaultdict(list)
    for _ in range(m):
        a,b=map(int,input().split())
        a-=1
        b-=1
        graph[a].append(b)
        graph[b].append(a)
    a=sp
    dist_0=bfs(0,n)
    dist_n=bfs(n-1,n)
    ans=[]
    for i in range(k):
        ans.append((dist_0[a[i]]-dist_n[a[i]],a[i]))
    ans.sort()
    mx=[0]
    for el in ans[::-1]:
        mx.append(max(mx[-1],dist_n[el[1]]))
    mx=mx[::-1]
    res=0
    for i in range(k-1):
        curr=min(dist_0[n-1], 1+dist_0[ans[i][1]]+mx[i+1])
        res=max(res,curr)
    print(res)
        
                            
    
#----------------------------------------------------------------------------------------
 
 
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