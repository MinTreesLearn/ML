import queue
from sys import stdin, stdout
from queue import PriorityQueue
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
        
mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x%y else 0
def ceil(a,b): return (a+b-1)//b
  
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 


n, m = mp()
roads = []
cons = dd(list)
fwd = dd(list)
for i in range(m):
    x, y = mp()
    cons[y-1].append(x-1)
    fwd[x-1].append(y-1)
k = iinp()
route = lmp()
end = route[-1]-1
dist = l1d(n, inf)
vis = l1d(n, False)
def bfs(ind, d):
    st = deque()
    st.appendleft((ind, d))
    vis[ind] = True
    d += 1
    while(len(st)):
        x, d = st.pop()
        dist[x] = min(dist[x], d)
        for i in cons[x]:
            if not vis[i]:
                vis[i] = True
                st.appendleft((i, d+1))

bfs(end, 0)
prev = route[0]-1
mn = 0
mx = 0
md = dd(int)
for i in dist:
    md[i]+=1
for i in range(1, k):
    cur = route[i]-1
    if dist[cur]>=dist[prev]:
        mn += 1
        mx += 1
    else:
        flg = False
        for f in fwd[prev]:
            if f!=cur and dist[f]==dist[prev]-1:
                flg = True
                break
        if flg: mx += 1
    prev = cur
print(mn, mx)