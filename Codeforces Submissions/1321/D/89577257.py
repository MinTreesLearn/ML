n, m = map(int, input().split())
u = []
r = []
for i in range(n):
    u.append([])
    r.append([])
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    u[b].append(a)
    r[a].append(b)
k = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))
q = [p[-1]]
d = [100000000000] * n
d[p[-1]] = 0
q0 = 0
while len(q) > q0:
    v = q[q0]
    q0 += 1
    for i in u[v]:
        if d[i] > d[v] + 1:
            d[i] = d[v] + 1
            q.append(i)
mn = 0
mx = 0
for i in range(k - 1):
    v, w = p[i], p[i + 1]
    if d[w] > d[v] - 1:
        mn += 1
        mx += 1
        continue
    for y in r[v]:
        if d[y] == d[v] - 1 and y != w:
            mx += 1
            break
print(mn, mx)
    
