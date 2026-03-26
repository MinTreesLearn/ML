import sys
input = sys.stdin.readline

def make_tree(n):
    tree = [0] * (n + 1)
    return tree

def get_sum(i):
    s = 0
    while i > 0:
        s += tree[i]
        i -= i & -i
    return s

def get_sum_segment(s, t):
    ans = get_sum(t) - get_sum(s - 1)
    return ans

def add(i, x):
    while i <= n:
        tree[i] += x
        i += i & -i

n, m = map(int, input().split())
a = list(map(int, input().split()))
l = [i + 1 for i in range(n)]
for i in a:
    l[i - 1] = 1
x = []
y = [[] for _ in range(n + 1)]
for i in range(m):
    ai = a[i]
    if not y[ai]:
        x.append(ai)
    y[ai].append(i + 1)
tree = make_tree(n)
r = [-1] * n
for i in x:
    s = get_sum_segment(i, n)
    r[i - 1] = i + s
    add(i, 1)
for i in range(n):
    if r[i] == -1:
        r[i] = i + get_sum_segment(i + 1, n) + 1
n, m = m, n
tree = make_tree(n)
inf = 1919810
for i in range(1, m + 1):
    if y[i]:
        add(y[i][0], 1)
    y[i].append(inf)
    y[i].reverse()
for i in range(n):
    j = a[i]
    c = y[j].pop()
    d = y[j][-1]
    r[j - 1] = max(r[j - 1], get_sum_segment(c, min(d, n)))
    if d ^ inf:
        add(d, 1)
ans = []
for l0, r0 in zip(l, r):
    ans.append(str(l0) + " " + str(r0))
sys.stdout.write("\n".join(ans))