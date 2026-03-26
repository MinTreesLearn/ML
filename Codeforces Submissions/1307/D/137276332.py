from collections import deque
import sys

n,m,k = map(int,sys.stdin.readline().split())

a = list(map(int,sys.stdin.readline().split()))

g = [[] for _ in range(n+1)]

for _ in range(m):
    x,y = map(int,sys.stdin.readline().split())
    g[x].append(y)
    g[y].append(x)

def bfs(start):
    hold = [0]*(n+1)
    visited = [False]*(n+1)
    q = deque()
    q.append(start)
    h = 0
    while len(q)>0:
        for _ in range(len(q)):
            node = q.popleft()
            visited[node] = True
            hold[node] = h
            for child in g[node]:
                if not(visited[child]):
                    visited[child] = True
                    q.append(child) 
        h+=1
    return hold

x = bfs(1) #dis 1 to i 
y = bfs(n) #dis i to n

arr = sorted([(x[i]-y[i],i) for i in a])
pref,ans = -1e9,-1e9

for v,node in arr:
    ans = max(ans,pref+y[node])
    pref = max(pref,x[node])

print(min(x[n],ans+1))