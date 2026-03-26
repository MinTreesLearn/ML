import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def update(l, r, s):
    q, ll, rr, i = [1], [0], [l1 - 1], 0
    while len(q) ^ i:
        j = q[i]
        l0, r0 = ll[i], rr[i]
        if l <= l0 and r0 <= r:
            lazy[j] += s
            i += 1
            continue
        m0 = (l0 + r0) >> 1
        if j < l1 and lazy[j]:
            lazy[j << 1] += lazy[j]
            lazy[j << 1 ^ 1] += lazy[j]
            lazy[j] = 0
        if l <= m0 and l0 <= r:
            q.append(j << 1)
            ll.append(l0)
            rr.append(m0)
        if l <= r0 and m0 + 1 <= r:
            q.append(j << 1 ^ 1)
            ll.append(m0 + 1)
            rr.append(r0)
        i += 1
    for i in reversed(q):
        if i < l1:
            j, k = i << 1, i << 1 ^ 1
            tree[i] = max(tree[j] + lazy[j], tree[k] + lazy[k])
    return

n, m, p = map(int, input().split())
a = [tuple(map(int, input().split())) for _ in range(n)]
b = [tuple(map(int, input().split())) for _ in range(m)]
xyz = [tuple(map(int, input().split())) for _ in range(p)]
l = pow(10, 6) + 5
s = [0] * l
for b0, _ in b:
    s[b0] = 1
for i in range(1, l):
    s[i] += s[i - 1]
c = s[-1]
l1 = pow(2, (c + 5).bit_length())
l2 = 2 * l1
inf = 2 * pow(10, 9) + 1
tree, lazy = [-inf] * l2, [0] * l2
ma1 = -inf
for b0, cb in b:
    ma1 = max(ma1, -cb)
    tree[s[b0] + l1] = max(tree[s[b0] + l1], -cb)
for i in range(l1 - 1, 0, -1):
    tree[i] = max(tree[2 * i], tree[2 * i + 1])
da = [-inf] * l
dx = [[] for _ in range(l)]
ma2 = -inf
for a0, ca in a:
    ma2 = max(ma2, -ca)
    da[a0] = max(da[a0], -ca)
for x, y, z in xyz:
    dx[x].append((y, z))
ans = ma1 + ma2
for i in range(1, l):
    if da[i] ^ -inf:
        ans = max(ans, tree[1] + lazy[1] + da[i])
    for y, z in dx[i]:
        update(s[y] + 1, c + 1, z)
print(ans)