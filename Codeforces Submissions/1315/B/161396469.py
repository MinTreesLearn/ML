from collections import deque
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def bfs(s):
    q = deque()
    q.append(s)
    dist = [inf] * (n + 1)
    dist[s] = 0
    ans0 = n
    while q:
        i = q.popleft()
        di = dist[i]
        if di > p:
            return ans0
        ans0 = min(ans0, i)
        for j, c in G[i]:
            dist[j] = di + c
            q.append(j)
    return ans0

t = int(input())
ans = []
inf = pow(10, 9) + 1
for _ in range(t):
    a, b, p = map(int, input().split())
    s = list(input().rstrip())
    n = len(s)
    x = 0
    y = []
    for i in range(n):
        if x ^ s[i]:
            x = s[i]
            y.append(i + 1)
    if y[-1] ^ n:
        y.append(n)
    G = [[] for _ in range(n + 1)]
    for i in range(len(y) - 1):
        k = y[i]
        c = a if s[k - 1] & 1 else b
        for j in range(y[i] + 1, y[i + 1] + 1):
            G[j].append((k, c))
    ans0 = bfs(n)
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))