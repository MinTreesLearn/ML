from collections import deque
from sys import stdin
input = stdin.readline
II = lambda :int(input())
MI = lambda :map(int,input().split())
MI0 = lambda:map(lambda x:int(x)-1,input().split())
LI = lambda :list(map(int,input().split()))
LI0 = lambda :list(map(lambda x:int(x)-1,input().split()))
ANS = []
#文字列出力はListでつくってから''.join(ANS),文字列結合は遅い
n = int(input())
edge = [[] for _ in range(n)]
for _ in range(n-1):
    u,v = MI0()
    edge[u].append(v)
    edge[v].append(u)
def d():
    bfs = [-1] * n
    maxindex = 0
    mx = -1
    q = deque()
    q.append(0)
    bfs[0] = 0
    while q:
        now = q.popleft()
        if bfs[now] > mx:
            maxindex = now
            mx = bfs[now]
        for nx in edge[now]:
            if bfs[nx] == -1:
                bfs[nx] = bfs[now] + 1
                q.append(nx)
    s = maxindex
    maxindex = 0
    mx = -1
    q.append(s)
    bfs = [-1] * n
    bfs[s] = 0
    memo = [-1] * n
    while q:
        now = q.popleft()
        if bfs[now] > mx:
            maxindex = now
            mx = bfs[now]
        for nx in edge[now]:
            if bfs[nx] == -1:
                bfs[nx] = bfs[now] + 1
                memo[nx] = now
                q.append(nx)
    t = maxindex
    q = deque()
    q.append(t)
    route = []
    while q:
        now = q.popleft()
        if now == -1:
            break
        route.append(now)
        back = memo[now]
        q.append(back)
    return route
q = deque()
route = d()
bfs = [-1] * n
for v in route:
    bfs[v] = 0
    q.append(v)
mxindex = route[0]
mx = -1
while q:
    now = q.popleft()
    if bfs[now] > mx:
        mx = bfs[now]
        mxindex = now
    for nx in edge[now]:
        if bfs[nx] == -1:
            bfs[nx] = bfs[now] + 1
            q.append(nx)
if mxindex in route:
    print(len(route)-1)
    print(route[0]+1,route[1]+1,route[-1]+1)
else:
    print(len(route)-1 + mx)
    print(route[0]+1,route[-1]+1,mxindex+1)