import sys, os
input = sys.stdin.buffer.readline

def f(u, v):
    os.write(1, b"%s %d %d\n" % (a, u, v))
    w = int(input())
    return w

def bfs(s):
    q, k = [s], 0
    visit[s] = 1
    while len(q) ^ k:
        i = q[k]
        for j in G[i]:
            if not visit[j]:
                q.append(j)
                visit[j] = 1
        k += 1
    return

n = int(input())
G = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
a, b = "?".encode(), "!".encode()
visit = [0] * (n + 1)
while True:
    x = []
    for i in range(1, n + 1):
        if visit[i]:
            continue
        c = 0
        for j in G[i]:
            if not visit[j]:
                c += 1
        if c <= 1:
            x.append(i)
        if len(x) == 2:
            break
    if len(x) == 2:
        u, v = x
        w = f(u, v)
        visit[w] = 1
        if not visit[u]:
            bfs(u)
        if not visit[v]:
            bfs(v)
        visit[w] = 0
    elif len(x) == 1:
        r = x[0]
        os.write(1, b"%s %d\n" % (b, r))
        exit()