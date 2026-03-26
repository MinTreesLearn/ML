import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

def err():
    print('-1'); exit()
n = inp()
g = [[] for _ in range(n)]
d = []
for i in range(n-1):
    a,b = inpl()
    a,b = a-1,b-1
    g[a].append(b)
    g[b].append(a)
    if a>b: a,b = b,a
    d.append([a,b])
bea = [[-1]*n for _ in range(n)]
cnt = [0] * (10**6+10)
m = inp()
pas = [inpl() for _ in range(m)]
pas.sort(key = lambda x:x[2])
root = []
for i,(a,b,c) in enumerate(pas):
    a,b = a-1,b-1
    pre = [-1] * n
    q = deque([a])
    f = True
    while q and f:
        nv = q.popleft()
        for v in g[nv]:
            if v == pre[nv]: continue
            pre[v] = nv
            if v == b:
                ro = [v]
                while v != a:
                    s,t = v,pre[v]
                    if s>t: s,t = t,s
                    bea[s][t] = c
                    ro.append(pre[v])
                    v = pre[v]
                root.append(ro[::-1])
                f = False
            q.append(v)
for i,(a,b,c) in enumerate(pas):
    a,b = a-1,b-1
    bad = True
    for j in range(len(root[i])-1):
        s,t = root[i][j], root[i][j+1]
        if s>t: s,t = t,s
        if bea[s][t] == c: bad = False; break
    if bad: err()

res = []
for i in range(n-1):
    a,b = d[i]
    now = bea[a][b]
    if now == -1:
        now = 1
    res.append(now)
print(*res)