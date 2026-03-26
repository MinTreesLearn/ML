import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def lazy_segment_tree(n):
    n0 = 1
    while n0 < n:
        n0 *= 2
    tree = [0] * (2 * n0)
    lazy = [0] * (2 * n0)
    return tree, lazy

def eval(s, t, a):
    b = []
    u, v = [0, len(tree) // 2 - 1], [0, len(tree) // 2 - 1]
    x, y = 1, 1
    while u[0] ^ u[1]:
        lx = lazy[x]
        b.append(x)
        tree[x] += lx
        lazy[2 * x] += lx
        lazy[2 * x + 1] += lx
        lazy[x] = 0
        ly = lazy[y]
        b.append(y)
        tree[y] += ly
        lazy[2 * y] += ly
        lazy[2 * y + 1] += ly
        lazy[y] = 0
        u0, u1 = u
        if u0 <= s <= (u0 + u1) // 2:
            u1 = (u0 + u1) // 2
            x = 2 * x
        else:
            u0 = (u0 + u1) // 2 + 1
            x = 2 * x + 1
        u = [u0, u1]
        v0, v1 = v
        if v0 <= t <= (v0 + v1) // 2:
            v1 = (v0 + v1) // 2
            y = 2 * y
        else:
            v0 = (v0 + v1) // 2 + 1
            y = 2 * y + 1
        v = [v0, v1]
    tree[x] += lazy[x]
    lazy[x] = 0
    tree[y] += lazy[y]
    lazy[y] = 0
    return b

def update(s, t, x):
    s0, t0 = s, t
    s += len(tree) // 2
    t += len(tree) // 2
    a = set()
    while s <= t:
        if s % 2 == 0:
            s //= 2
        else:
            a.add(s)
            lazy[s] += x
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            a.add(t)
            lazy[t] += x
            t = (t - 1) // 2
    b = eval(s0, t0, a)
    s0 += len(tree) // 2
    t0 += len(tree) // 2
    while b:
        i = b.pop()
        tree[i] = min(tree[2 * i] + lazy[2 * i], tree[2 * i + 1] + lazy[2 * i + 1])
    return

def get_min(s, t):
    s0, t0 = s, t
    s += len(tree) // 2
    t += len(tree) // 2
    a = set()
    while s <= t:
        if s % 2 == 0:
            s //= 2
        else:
            a.add(s)
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            a.add(t)
            t = (t - 1) // 2
    eval(s0, t0, a)
    ans = inf
    for i in a:
        ans = min(ans, tree[i] + lazy[i])
    return ans

n = int(input())
p = list(map(int, input().split()))
a = list(map(int, input().split()))
inf = pow(2, 31) - 1
tree, lazy = lazy_segment_tree(n + 5)
x = [0] * (n + 1)
for i in range(n):
    x[p[i]] = a[i]
for i in range(1, n + 1):
    x[i] += x[i - 1]
for i in range(1, n + 1):
    update(i + 2, i + 2, x[i])
ans = inf
for i in range(n - 1):
    update(p[i] + 2, n + 3, -a[i])
    update(1, p[i], a[i])
    ans = min(ans, get_min(2, n + 1))
print(ans)