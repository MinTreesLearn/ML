import sys
input = sys.stdin.readline
from bisect import bisect_left

n = int(input())
g = [[] for _ in range(n)]
c = [0] * n
for i in range(n):
    p, c[i] = map(int, input().split())
    if p != 0:
        g[p - 1].append(i)
    else:
        root = i
s = [root]
v = [0] * n
d = [[] for _ in range(n)]
idx = 0
while s:
    p = s.pop()
    if v[p] == 0:
        s.append(p)
        v[p] = 1
        for node in g[p]:
            s.append(node)
    else:
        for node in g[p]:
            d[p] += d[node]
        if len(d[p]) < c[p]:
            print('NO')
            exit(0)
        d[p].insert(c[p], p)
res = [0] * n
x = d[root]
for i in range(n):
    res[x[i]] = i + 1
print('YES')
print(*res)