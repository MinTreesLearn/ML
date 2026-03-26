from collections import defaultdict
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def segment_tree(n):
    i = 2
    while True:
        if i >= n * 2:
            tree = [-inf] * i
            break
        else:
            i *= 2
    return tree

def update(i, x):
    i += len(tree) // 2
    tree[i] = x
    i //= 2
    while True:
        if i == 0:
            break
        tree[i] = max(tree[2 * i], tree[2 * i + 1])
        i //= 2
    return

def get_max(s, t):
    s += len(tree) // 2
    t += len(tree) // 2
    ans = -inf
    while s <= t:
        if s % 2 == 0:
            s //= 2
        else:
            ans = max(ans, tree[s])
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            ans = max(ans, tree[t])
            t = (t - 1) // 2
    return ans

n = int(input())
m = list(map(int, input().split()))
d = defaultdict(lambda : [])
for i in range(n):
    d[m[i]].append(i)
x = list(d.keys())
x.sort()
inf = 1
tree = segment_tree(n)
dp1 = [0] * (n + 1)
for i in x:
    for j in d[i]:
        k = get_max(0, j)
        dp1[j] = dp1[k] + i * (j - k)
        update(j, j)
inf = n
tree = segment_tree(n)
dp2 = [0] * (n + 1)
for i in x:
    for j in reversed(d[i]):
        k = -get_max(j, n - 1)
        dp2[j] = dp2[k] + i * (k - j)
        update(j, -j)
s = 0
k = -1
c = 0
dp1.pop()
dp2.pop()
for i, j, l in zip(dp1, dp2, m):
    if s < i + j - l:
        s = i + j - l
        k = c
    c += 1
a = [0] * n
a[k] = m[k]
for j in range(k - 1, -1, -1):
    a[j] = min(a[j + 1], m[j])
    s += a[j]
for j in range(k + 1, n):
    a[j] = min(a[j - 1], m[j])
    s += a[j]
sys.stdout.write(" ".join(map(str, a)))