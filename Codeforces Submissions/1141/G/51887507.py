import os
from io import BytesIO
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

from collections import defaultdict
from itertools import islice

def solve():
    n, k = map(int, input().split())
    G = [list() for _ in range(n)]
    E = []
    ans = defaultdict(lambda: 1)

    for _ in range(n-1):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        G[u].append(v)
        G[v].append(u)
        E.append((u, v))

    V = list(range(n))
    V.sort(key=lambda v: -len(G[v]))

    r = len(G[V[k]])

    visited = [False] * n
    stack = []
    for u in islice(V, k, None):
        if not visited[u]:
            stack.append((u, 0))
            while stack:
                u, skip = stack.pop()
                visited[u] = True
                e = 0
                for v in G[u]:
                    if not visited[v]:
                        e += 1
                        if e == skip:
                            e += 1
                        ans[(u, v)] = e
                        if len(G[v]) <= r:
                            stack.append((v, e))

    print(r)
    out = []
    for u, v in E:
        if (u, v) not in ans:
            u, v = v, u
        out.append(str(ans[(u, v)]))
    print(' '.join(out))


solve()