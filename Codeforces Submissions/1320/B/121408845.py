from collections import deque


n, m = map(int, input().split())

g = [[] for _ in range(n)]
g_n = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    g_n[u-1].append(v-1)
    g[v-1].append(u-1)

k = int(input())

path = list(map(int, input().split()))

q = deque()
distance = [-1 for _ in range(n)]

distance[path[k-1]-1] = 0
q.append(path[k-1]-1)

while len(q):
    u = q.popleft()

    for v in g[u]:
        if distance[v] == -1:
            distance[v] = distance[u] + 1
            q.append(v)

rebuild = 0
rebuild_max = 0

for i in range(1, k-1):
    

    if distance[path[i]-1] == distance[path[i-1]-1] - 1:
        for w in g_n[path[i-1]-1]:
            if w != path[i]-1 and distance[w] == distance[path[i]-1]:
                rebuild_max += 1
                break
    else:
        rebuild += 1

print(rebuild, rebuild + rebuild_max)