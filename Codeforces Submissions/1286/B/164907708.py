import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def bfs(s):
    p = [s]
    k = 0
    visit = [0] * (n + 1)
    visit[s] = 1
    parent = [-1] * (n + 1)
    while len(p) ^ k:
        i = p[k]
        for j in G[i]:
            if not visit[j]:
                visit[j] = 1
                p.append(j)
                parent[j] = i
        k += 1
    return p, parent

n = int(input())
G = [[] for _ in range(n + 1)]
c = [0]
for i in range(1, n + 1):
    p, c0 = map(int, input().split())
    if p:
        G[p].append(i)
    else:
        r = i
    c.append(c0)
p, parent = bfs(r)
dp = [1] * (n + 1)
for i in range(-1, -n, -1):
    j = p[i]
    k = parent[j]
    dp[k] += dp[j]
ans = "YES"
for i in range(1, n + 1):
    if dp[i] <= c[i]:
        ans = "NO"
        break
print(ans)
if ans == "NO":
    exit()
dp = [[] for _ in range(n + 1)]
while p:
    i = p.pop()
    dpi, ci = dp[i], c[i]
    if not ci:
        dpi.append(i)
    for j in G[i]:
        for k in dp[j]:
            dpi.append(k)
            if len(dpi) == ci:
                dpi.append(i)
a = [0] * n
x = 1
for i in dp[r]:
    a[i - 1] = x
    x += 1
sys.stdout.write(" ".join(map(str, a)))