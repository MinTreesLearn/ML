from heapq import *

n,m=map(int,input().split())
g=[ [] for i in range(n+1)]
to=[ [] for i in range(n+1)]
d=[ 0x3f3f3f3f for i in range(n+1)]
vis=[ 0 for i in range(n+1)]

def dij(s):
    hp=[]
    d[s]=0
    heappush(hp,(0,s))
    while hp:
        val,iid=heappop(hp)
        if(vis[iid]==1):
            continue
        vis[iid]=1
        for son in g[iid]:
            if(d[son]>d[iid]+1):
                d[son]=d[iid]+1
                heappush(hp,(d[son],son))
        
for i in range(m):
    u,v=map(int,input().split())
    g[v].append(u)
    to[u].append(v)
k=int(input())
p=list(map(int,input().split()))
dij(p[-1])
mn=0
mx=0
for i in range(len(p)-1):
    u=p[i]
    v=p[i+1]
    if(d[u]!=d[v]+1):
        mn+=1
    for iid in to[u]:
        if(iid==v):
            continue;
        if(d[u]==d[iid]+1):
            mx+=1
            break
print(mn,mx)
        
