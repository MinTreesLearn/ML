import sys
input=sys.stdin.buffer.readline

from collections import deque

def dfs():
    visited=[0 for i in range(n+1)]
    queue=deque()
    queue.append([1,0])
    add=0
    while(queue):
        par=queue.popleft()
        if(visited[par[0]]==1):
            continue
        visited[par[0]]=1
        add=(marked[par[1]]+1)%fix
        for child in graph[par[0]]:
            if(visited[child[0]]==0):
                marked[child[1]]=add
                add=(add+1)%fix
                queue.append([child[0],child[1]])


n,k=map(int,input().split())
graph=[[] for i in range(n+1)]
counted=[0 for i in range(n+1)]
for i in range(n-1):
    a,b=map(int,input().split())
    counted[a]+=1
    counted[b]+=1
    graph[a].append([b,i])
    graph[b].append([a,i])
arr=[]
for i in range(1,n+1):
    arr.append(counted[i])
arr.sort(reverse=True)
fix=arr[k]
marked=[0 for i in range(n+1)]
marked[0]=-1
dfs()
print(max(marked)+1)
for i in range(n-1):
    print(marked[i]+1,end=' ')
print()