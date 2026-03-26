import sys
import collections
input = sys.stdin.readline

ints = lambda: list(map(int, input().split()))
 
n, m, k = ints()
special = ints()
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = ints()
    graph[x].append(y)
    graph[y].append(x)
 
distances = [[-1, -1] for _ in range(n + 1)]

def bfs(start):
    d = [-1 for _ in range(n + 1)]
    q = collections.deque([start])
    depth = 1
    d[start] = 0

    while q:
        for _ in range(len(q)):
            node = q.popleft()
            
            for nb in graph[node]:
                if d[nb] == -1:
                    q.append(nb)
                    d[nb] = depth
        depth += 1
    return d

d1 = bfs(1)
d2 = bfs(n)

ans = d2[1]
s_distances = [(d1[i], d2[i]) for i in special]
s_distances.sort(key=lambda x: x[1], reverse=True)
mx = 0
for i in range(len(s_distances) - 1):
    l = s_distances[i + 1][1] + 1 + s_distances[i][0]
    mx = max(mx, l)
print(min(ans, mx))
 