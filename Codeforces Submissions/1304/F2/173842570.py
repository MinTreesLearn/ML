import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def update(l, r, s):
    q, lr, i = [1], [(0, l1 - 1)], 0
    while len(q) ^ i:
        j = q[i]
        l0, r0 = lr[i]
        if l <= l0 and r0 <= r:
            lazy[j] += s
            i += 1
            continue
        m0 = (l0 + r0) // 2
        if j < l1:
            lazy[2 * j] += lazy[j]
            lazy[2 * j + 1] += lazy[j]
            lazy[j] = 0
        if l <= m0 and l0 <= r:
            q.append(2 * j)
            lr.append((l0, m0))
        if l <= r0 and m0 + 1 <= r:
            q.append(2 * j + 1)
            lr.append((m0 + 1, r0))
        i += 1
    while q:
        i = q.pop()
        if i < l1:
            tree[i] = max(tree[2 * i] + lazy[2 * i], tree[2 * i + 1] + lazy[2 * i + 1])
    return

n, m, k = map(int, input().split())
if n == 1:
    s = list(map(int, input().split()))
    c = [0]
    for i in s:
        c.append(i + c[-1])
    ans = 0
    for i in range(m - k + 1):
        ans = max(ans, c[i + k] - c[i])
    print(ans)
    exit()
s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))
c1, c2 = [0], [0]
for i in s1:
    c1.append(i + c1[-1])
for i in s2:
    c2.append(i + c2[-1])
n0 = m - k + 1
dp0 = [0] * n0
for i in range(n0):
    dp0[i] = c1[i + k] - c1[i] + c2[i + k] - c2[i]
s1, c1 = s2, c2
l1 = pow(2, (2 * n0).bit_length())
l2 = 2 * l1
u = [max(i - k + 1, 0) for i in range(m)]
v = [min(i, m - k) for i in range(m)]
for x in range(n - 1):
    s2 = [0] * m if x == n - 2 else list(map(int, input().split()))
    c2 = [0]
    for i in s2:
        c2.append(i + c2[-1])
    tree, lazy = [0] * l2, [0] * l2
    for i in range(n0):
        tree[i + l1] = dp0[i]
    for i in range(l1 - 1, 0, -1):
        tree[i] = max(tree[2 * i], tree[2 * i + 1])
    for i in range(k - 1):
        update(u[i], v[i], -s1[i])
    dp = [0] * n0
    for i in range(n0):
        j = i + k - 1
        update(u[j], v[j], -s1[j])
        dp[i] = c1[i + k] - c1[i] + c2[i + k] - c2[i] + tree[1] + lazy[1]
        update(u[i], v[i], s1[i])
    dp0 = dp
    s1, c1 = s2, c2
ans = max(dp0)
print(ans)