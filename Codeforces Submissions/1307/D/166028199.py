from collections import deque
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def bfs(s):
    q = deque()
    q.append(s)
    dist = [inf] * (n + 1)
    dist[s] = 0
    while q:
        i = q.popleft()
        di = dist[i]
        for j in G[i]:
            if dist[j] == inf:
                dist[j] = di + 1
                q.append(j)
    return dist

def sparse_table(a):
    table = []
    s0, l = a, 1
    table.append(s0)
    while 2 * l <= len(a):
        s = [max(s0[i], s0[i + l]) for i in range(len(s0) - l)]
        table.append(list(s))
        s0 = s
        l *= 2
    return table

def get_max(l, r, table):
    d = len(bin(r - l + 1)) - 3
    ans = max(table[d][l], table[d][r - pow2[d] + 1])
    return ans

def binary_search(c1, c2, r):
    m = (c1 + c2 + 1) // 2
    while abs(c1 - c2) > 1:
        m = (c1 + c2 + 1) // 2
        if ok(m, r):
            c1 = m
        else:
            c2 = m
    m += 1
    while not ok(m, r):
        m -= 1
    return m

def ok(m, r):
    l = v[max(0, m - x0)]
    if l > r:
        return False
    return True if get_max(l, r, table) >= m - y0 else False

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
inf = pow(10, 9) + 1
pow2 = [1]
for _ in range(20):
    pow2.append(2 * pow2[-1])
G = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    G[x].append(y)
    G[y].append(x)
dist1 = bfs(1)
dist2 = bfs(n)
u = []
for i in a:
    u.append((dist1[i], dist2[i]))
u.sort()
x, y = [], []
for i, j in u:
    x.append(i)
    y.append(j)
table = sparse_table(y)
v = [0] * (n + 5)
for i in range(1, k):
    for j in range(x[i - 1] + 1, x[i] + 1):
        v[j] = i
for i in range(x[-1] + 1, n + 5):
    v[i] = k
ans = 0
for i in range(k - 1, 0, -1):
    x0, y0 = y.pop(), x.pop()
    z = binary_search(0, n, i - 1) + 1
    ans = max(ans, z)
ans = min(ans, dist1[n])
print(ans)