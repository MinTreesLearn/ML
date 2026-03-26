from collections import deque
 
 
N = int(input())
 
m = [[None]*N for i in range(N)]
v = [[False]*N for i in range(N)]
 
for i in range(N):
	r = list(map(int, input().split()))
	for j in range(N):
		x, y = r[2*j] - 1, r[2*j + 1] - 1
		m[i][j] = (x, y)
 
def bfs(x, y):
	# x, y is the coordinate of our input
	q = deque()
	q.append((x, y))
	while len(q):
		x, y = q.popleft()
		for i, j, d in [(x - 1, y, 'D'), (x + 1, y, 'U'), (x, y - 1, 'R'), (x, y + 1, 'L')]:
			if i != -1 and i != N and j != -1 and j != N:
				if m[i][j] != m[x][y]: 
					continue
				if not v[i][j]:
					v[i][j] = d
					q.append((i, j))
 
for i in range(N):
	for j in range(N):
		if m[i][j] == (i, j):
			v[i][j] = 'X'
			bfs(i, j)
		elif m[i][j] == (-2, -2):
			for a, b, nxt, prev in [(i - 1, j, 'U', 'D'), (i + 1, j, 'D', 'U'), (i, j - 1,'L', 'R'), (i, j + 1, 'R', 'L')]:
				if a != -1 and a != N and b != -1 and b != N:
					if m[i][j] != m[a][b]: 
						continue
					else:
						v[i][j] = nxt
						v[a][b] = prev
						break 
 
for i in range(N):
	for j in range(N):
		if not v[i][j]:
			print('INVALID')
			exit()
 
print('VALID')
print('\n'.join([''.join(r) for r in v]))
 
  	    	 	 		 	  						 	 		  	