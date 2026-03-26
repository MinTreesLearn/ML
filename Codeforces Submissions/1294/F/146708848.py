from collections import deque

def bfs(st,L,d):
	q = deque()
	q.append(st)
	d[st] = 0
	while q:
		a = q.popleft()
		for i in L[a]:
			if d[i] == float('inf'):
				q.append(i)
				d[i] = d[a] + 1 
	

def solve():
	n = int(input())
	tree = [[] for i in range(n+1)]
	for i in range(n-1):
		a,b = map(int,input().split())
		tree[a].append(b)
		tree[b].append(a)

	
	d = [float('inf') for i in range(n+1)]

	bfs(1,tree,d)
	a = 1
	for i in range(1,len(d)):
		if d[i] > d[a]:
			a = i
			
	e = [float('inf') for i in range(n+1)]

	bfs(a,tree,e)
	b = 1
	for i in range(1,len(e)):
		if e[i] > e[b]:
			b = i
	
	f = [float('inf') for i in range(n+1)]

	bfs(b,tree,f)
	
	for i in range(1,4):
		if i!= a and i != b:
			c = i
			

	mx = (e[c] + f[c] + f[a]) // 2
	for i in range(1,n+1):
		if (e[i]+f[i]+f[a]) // 2 > mx:
			mx = (e[i]+f[i]+f[a]) // 2
			c = i

	print(mx)
	print(a,b,c)
			
solve()
	
	

