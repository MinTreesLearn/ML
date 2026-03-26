import sys
input = sys.stdin.readline
from collections import deque
 
def bfs(root):
	vis=[0]*n
	queue=[root,-1]
	queue=deque(queue)
	vis[root]=1
	d=0
	while len(queue)!=1:
		element = queue.popleft()
		if element==-1:
			queue.append(-1)
			d+=1
			continue
		vis[element] = 1
		dist[element] = d
		for i in graph[element]:
			if not vis[i]:
				queue.append(i)
				vis[i]=1
 
n,m=map(int,input().split())
graph=[[] for i in range(n)]
t=[[] for i in range(n)]
for i in range(m):
	u,v=map(int,input().split())
	graph[v-1].append(u-1)
	t[u-1].append(v-1)
k=int(input())
p=list(map(int,input().split()))
dist=[0 for i in range(n)]
bfs(p[-1]-1)
# print (dist)
maxx=0
minn=0
for i in range(k-1):
	if dist[p[i+1]-1]>dist[p[i]-1]-1:
		maxx+=1
		minn+=1
	else:
		count=0
		# print (i,p[i],t[p[i]])
		for j in t[p[i]-1]:
			if dist[j]==dist[p[i]-1]-1:
				count+=1
		if count>=2:
			maxx+=1
print (minn,maxx)