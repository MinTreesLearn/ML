import bisect
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_min(s, t):
    s += l1
    t += l1
    ans = inf
    while s <= t:
        if s % 2 == 0:
            s //= 2
        else:
            ans = min(ans, mi[s])
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            ans = min(ans, mi[t])
            t = (t - 1) // 2
    return ans

def get_max(s, t):
    s += l1
    t += l1
    ans = -inf
    while s <= t:
        if s % 2 == 0:
            s //= 2
        else:
            ans = max(ans, ma[s])
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            ans = max(ans, ma[t])
            t = (t - 1) // 2
    return ans

def fenwick_tree(n):
    tree = [0] * (n + 1)
    return tree

def get_sum(i, tree):
    s = 0
    while i > 0:
        s += tree[i]
        i -= i & -i
    return s

def add(i, x, tree):
    while i < len(tree):
        tree[i] += x
        i += i & -i

n = int(input())
a, x = [], []
for i in range(n):
    sa, ea, sb, eb = map(int, input().split())
    a.append(ea * n + i)
    x.append((sa, ea, sb, eb))
a.sort()
u = []
inf = pow(10, 9) + 1
l1 = pow(2, n.bit_length())
l2 = 2 * l1
mi, ma = [inf] * l2, [-inf] * l2
ok = 1
z = [[] for _ in range(n + 1)]
s = set([inf, -inf])
for k in range(n):
    i = a[k] % n
    sa, ea, sb, eb = x[i]
    s.add(sb)
    s.add(eb)
    u.append(ea)
    c = bisect.bisect_left(u, sa)
    j = k + l1
    mi[j], ma[j] = eb, sb
    j //= 2
    while j:
        mi[j] = min(mi[2 * j], mi[2 * j + 1])
        ma[j] = max(ma[2 * j], ma[2 * j + 1])
        j //= 2
    z[c].append(i)
    if c < k and (get_min(c, k - 1) < sb or eb < get_max(c, k - 1)):
        ok = 0
        break
if ok:
    l, r = ma[l1:], mi[l1:]
    s = list(s)
    s.sort()
    d = dict()
    m = len(s)
    for i in range(m):
        d[s[i]] = i + 1
    cl, cr = fenwick_tree(m + 5), fenwick_tree(m + 5)
    for i in range(1, n + 1):
        add(d[l[i - 1]], 1, cl)
        add(d[r[i - 1]], 1, cr)
        for j in z[i]:
            _, _, sb, eb = x[j]
            if get_sum(d[sb] - 1, cr) ^ get_sum(d[eb], cl):
                ok = 0
                break
        if not ok:
            break
ans = "YES" if ok else "NO"
print(ans)