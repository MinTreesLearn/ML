
###pyrival template for fast IO
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
n=int(input());root=None
c=[None for x in range(n+1)]
parent=[None for x in range(n+1)]
for i in range(1,n+1):
    pi,ci=[int(x) for x in input().split()]
    c[i]=ci
    if pi==0:root=i
    parent[i]=pi

def parent_array_tograph(parent):
    l=len(parent);graph=dict()
    for i in range(1,l):
        if parent[i] not in graph:
            graph[parent[i]]=[i]
        else:
            graph[parent[i]].append(i)
    return graph
graph=parent_array_tograph(parent)

######directed
def dfs(graph,n,currnode):
    visited=[False for x in range(n+1)]
    stack=[currnode]
    ans=[]
    while stack:
        currnode=stack[-1]
        if visited[currnode]==False:
            visited[currnode]=True
            ans.append(currnode)
        if currnode in graph:
            for neighbour in graph[currnode]:
                if visited[neighbour]==False:
                    visited[neighbour]=True
                    stack.append(neighbour)
                    ans.append(neighbour)
                    break
            else:
                stack.pop() ####we are backtracking to previous node which is in  our stack
        else:
            stack.pop()
    return ans

ans=dfs(graph,n,root);
result=[None for x in range(n+1)]
value=[True for x in range(n+1)]
notpossibe=False
for i in range(len(ans)):
    ci=c[ans[i]]
    index=1
    while ci!=0 and index!=n+1:
        if value[index]==True:
            ci-=1
            index+=1
        else:index+=1
    while True:
        if index==n+1:
            notpossibe=True
            break
        if value[index]==True:
            value[index]=False
            result[ans[i]]=index
            break
        else:
            index+=1
    if notpossibe==True:
        break

if notpossibe==False:
    ######directed
    def dfs_count(graph,n,currnode):
        visited=[False for x in range(n+1)]
        count=0;root=currnode
        stack=[currnode]
        ans=[]
        while stack:
            currnode=stack[-1]
            if visited[currnode]==False:
                visited[currnode]=True
                if result[currnode]<result[root]:
                    count+=1
            if currnode in graph:
                for neighbour in graph[currnode]:
                    if visited[neighbour]==False:
                        visited[neighbour]=True
                        stack.append(neighbour)
                        if result[neighbour]<result[root]:
                            count+=1
                        break
                else:
                    stack.pop() ####we are backtracking to previous node which is in  our stack
            else:
                stack.pop()
        return count
    for i in range(1,n+1):
        if c[i]!=dfs_count(graph,n,i):
            print("NO")
            break
    else:
        print("YES")
        print(*result[1:])
else:
    print("NO")