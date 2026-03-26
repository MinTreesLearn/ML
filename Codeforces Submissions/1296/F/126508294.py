from collections import deque, defaultdict
import sys
input = sys.stdin.readline

def bfs(s):
    q = deque()
    q.append(s)
    visit = [0] * (n + 1)
    visit[s] = 1
    parent[s] = -1
    e[s] = -1
    while q:
        i = q.popleft()
        for j, c in G[i]:
            if not visit[j]:
                visit[j] = 1
                q.append(j)
                parent[j] = i
                e[j] = c
    return

n = int(input())
G = [[] for _ in range(n + 1)]
for i in range(n - 1):
    x, y = map(int, input().split())
    G[x].append((y, i))
    G[y].append((x, i))
m = int(input())
se = set()
d = defaultdict(lambda : [])
for _ in range(m):
    a, b, g = map(int, input().split())
    d[g].append((a, b))
    se.add(g)
se = list(se)
se.sort(reverse = True)
parent = [-1] * (n + 1)
e = [-1] * (n + 1)
f = [0] * (n - 1)
for i in se:
    for a, b in d[i]:
        ok = 0
        bfs(a)
        u = b
        while a ^ u:
            if not f[e[u]] or f[e[u]] == i:
                f[e[u]] = i
                ok = 1
            u = parent[u]
        if not ok:
            f = [-1]
            break
    if not ok:
        f = [-1]
        break
if ok:
    for i in range(n - 1):
        if not f[i]:
            f[i] = 114514
print(*f)