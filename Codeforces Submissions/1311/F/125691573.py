import heapq
import sys
input = sys.stdin.readline

def make_tree(n):
    tree = [0] * (n + 1)
    return tree

def get_sum(i, tree):
    s = 0
    while i > 0:
        s += tree[i]
        i -= i & -i
    return s

def add(i, x, tree):
    while i <= n:
        tree[i] += x
        i += i & -i

n = int(input())
x = list(map(int, input().split()))
v = list(map(int, input().split()))
u = list(set(v))
u.sort(reverse = True)
m = len(u)
d = dict()
for i in range(m):
    d[u[i]] = i + 2
tree = make_tree(n + 5)
cnt = make_tree(n + 5)
ans = 0
h = []
for i in range(n):
    heapq.heappush(h, (x[i], i))
sx = []
while h:
    xi, i = heapq.heappop(h)
    sx.append(xi)
    vi = v[i]
    di = d[vi]
    ans -= get_sum(di - 1, cnt) * xi - get_sum(di - 1, tree)
    add(di, xi, tree)
    add(di, 1, cnt)
for i in range(n - 1):
    ans += (i + 1) * (n - i - 1) * (sx[i + 1] - sx[i])
print(ans)