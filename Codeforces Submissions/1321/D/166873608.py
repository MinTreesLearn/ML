import sys
import collections
import math
input = sys.stdin.readline

ints = lambda: list(map(int, input().split()))

n, m = ints()
graph = [[] for _ in range(n + 1)]
f_graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = ints()
    graph[u].append(v)
    f_graph[v].append(u)
k = int(input())
path = ints()

d = [0 for _ in range(n + 1)]
q = collections.deque([(path[-1], 0)])
visited = {path[-1]: True}

while q:
    sz = len(q)
    for _ in range(sz):
        node, distance = q.popleft()

        for nb in f_graph[node]:
            if nb not in visited:
                visited[nb] = True
                q.append((nb, distance + 1))
                d[nb] = distance + 1


mn = 0
for i in range(k - 2, -1, -1):
    if d[path[i]] != d[path[i + 1]] + 1:
        mn += 1

mx = 0
for i in range(k - 2, -1, -1):
    best = d[path[i + 1]]
    flag = False
    for nb in graph[path[i]]:
        if nb != path[i + 1] and d[nb] <= best:
            flag = True
    if flag:
        mx += 1
print(mn, mx)