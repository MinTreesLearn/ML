import sys,os,io
from collections import deque
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n,m = [int(i) for i in input().split()]
graph = [[] for i in range (n)]
graph1 = [[] for i in range (n)]
for i in range (m):
    ui,vi = [int(i)-1 for i in input().split()]
    graph[vi].append(ui)
    graph1[ui].append(vi)
k = int(input())
p = [int(i)-1 for i in input().split()]
q = deque()
q.append(p[-1])
dis = [10**9]*n
dis[p[-1]]=0
cnt = [0]*n
while(len(q)):
    curr = q.popleft()
    for i in graph[curr]:
        if dis[i]>dis[curr]+1:
            dis[i]=dis[curr]+1
            cnt[i]=1
            q.append(i)
        elif dis[i]==dis[curr]+1:
            cnt[i]+=1
x = 0
# for i in p:
#     if cnt[i]>1:
#         x+=1
y = 0
arr = [[] for i in range (n)]
for i in range (n):
    arr[dis[i]].append(i)
for i in range (1,k):
    if dis[p[i]] > dis[p[i-1]]-1:
        y+=1
    else:
        for j in graph1[p[i-1]]:
            if j!=p[i] and dis[j]==dis[p[i]]:
                x+=1
                break

print(y , x + y)