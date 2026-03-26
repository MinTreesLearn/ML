from sys import stdin
input=lambda :stdin.readline()[:-1]
 
n=int(input())
edge=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(lambda x:int(x)-1,input().split())
  edge[a].append(b)
  edge[b].append(a)
 
def dfs(root):
  par=[-1]*n
  dist=[0]*n
  todo=[(root,-1)]
  while todo:
    v,p=todo.pop()
    for u in edge[v]:
      if u!=p:
        dist[u]=dist[v]+1
        todo.append((u,v))
        par[u]=v
  mx=max(dist)
  v0=dist.index(mx)
  return par,v0,mx
 
_,v0,_=dfs(0)
par,v1,mx=dfs(v0)
 
if mx==n-1:
  v2=0
  while v2==v0 or v2==v1:
    v2+=1
  print(n-1)
  print(v0+1,v1+1,v2+1)
  exit()
 
dist=[-1]*n
todo=[]
now=v1
dist[now]=0
todo.append(now)
while now!=v0:
  now=par[now]
  todo.append(now)
  dist[now]=0
 
while todo:
  v=todo.pop()
  for u in edge[v]:
    if dist[u]==-1:
      dist[u]=dist[v]+1
      todo.append(u)
 
v2=dist.index(max(dist))
print(mx+max(dist))
print(v0+1,v1+1,v2+1)