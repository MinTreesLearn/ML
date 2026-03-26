import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def bfs(s):
    q, k = [s], 0
    inf = pow(10, 9) + 1
    dist = [inf] * (n + 1)
    dist[s] = 0
    while len(q) ^ k:
        i = q[k]
        di = dist[i]
        for j in G[i]:
            if dist[j] == inf:
                dist[j] = di + 1
                q.append(j)
        k += 1
    return dist

n, m = map(int, input().split())
G = [[] for _ in range(n + 1)]
H = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    G[v].append(u)
    H[u].append(v)
k = int(input())
p = list(map(int, input().split()))
p.reverse()
s = p[0]
dist = bfs(s)
mi, ma = 0, 0
for i in range(1, k):
    d = dist[p[i]]
    if dist[p[i - 1]] ^ (d - 1):
        mi += 1
        ma += 1
    else:
        u = 0
        for j in H[p[i]]:
            if dist[j] == d - 1:
                u += 1
        if u >= 2:
            ma += 1
print(mi, ma)