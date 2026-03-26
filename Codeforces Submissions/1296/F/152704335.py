import sys


class graph:
    def __init__(self, n):
        self.n, self.gdict = n, [[] for _ in range(n + 1)]

    def add_edge(self, node1, node2, w=None):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)

    def subtree(self, v):
        queue, vis = [v], [False] * (n + 1)
        vis[v] = True
        while queue:
            s = queue.pop()

            for i1 in self.gdict[s]:
                if not vis[i1]:
                    queue.append(i1)
                    vis[i1] = True
                    par[i1], level[i1] = s, level[s] + 1


def lca(x, y):
    if level[x] < level[y]:
        x, y = y, x
    while level[x] > level[y]:
        p = par[x]
        ans[edges[p][x]] = mi
        x = p

    while x != y:
        p = par[x]
        ans[edges[p][x]] = mi
        x = p

        p = par[y]
        ans[edges[p][y]] = mi
        y = p


def check(x, y):
    mi_ = 10 ** 9
    if level[x] < level[y]:
        x, y = y, x
    while level[x] > level[y]:
        p = par[x]
        mi_ = min(ans[edges[p][x]], mi_)
        x = p

    while x != y:
        p = par[x]
        mi_ = min(ans[edges[p][x]], mi_)
        x = p

        p = par[y]
        mi_ = min(ans[edges[p][y]], mi_)
        y = p
    return mi_


input = sys.stdin.readline
n = int(input())
adj = [[int(x) for x in input().split()] for _ in range(n - 1)]
m = int(input())
a = [tuple([int(x) for x in input().split()]) for _ in range(m)]
ans = [1] * (n - 1)
edges = [[0] * (n + 1) for _ in range(n + 1)]
level, g = [0] * (n + 1), graph(n)
par = [-1] * (n + 1)

for _ in range(n - 1):
    u, v = adj[_]
    g.add_edge(u, v)
    edges[u][v] = edges[v][u] = _

a.sort(key=lambda x: x[2])
g.subtree(1)

for x, y, mi in a:
    lca(x, y)

for x, y, mi in a:
    mi_ = check(x, y)
    if mi_ != mi:
        exit(print(-1))

print(' '.join(map(str, ans)))
