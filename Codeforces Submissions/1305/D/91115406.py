from sys import stdin, stdout
input = stdin.buffer.readline
#print = stdout.write

n = int(input())
g = [[] for i in range(n + 1)]
vis = [0] * (n + 1)
deg = []
for i in range(n - 1):
	a, b = map(int, input().split())
	g[a].append(b)
	g[b].append(a)

def ask(a, b):
	print('?', a, b, flush=True)
	return int(input())

def dfs(v, p):
	for ch in g[v]:
		if not vis[ch]:
			deg[v] += 1
			if ch != p:
				dfs(ch, v)
			
def solve():
	global deg
	deg = [0] * (n + 1)
	for i in range(1, n + 1):
		if not vis[i]:
			dfs(i, 0)
			break
	a = b = 0
	for i in range(1, n + 1):
		if deg[i] == 1:
			if not a:
				a = i
			else:
				b = i
				break
	if a + b == 0:
		for i in range(1, n + 1):
			if not vis[i]:
				exit(print('!', i, flush=True))
	x = ask(a, b)
	if x in [a, b]:
		exit(print('!', x, flush=True))
	vis[a] = vis[b] = 1
		
while 1:
	solve()
