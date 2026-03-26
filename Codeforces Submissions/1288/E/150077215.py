import sys


class segmenttree:
    def __init__(self, n, default=0, func=lambda a, b: a + b):
        self.tree, self.n, self.func, self.default = [0] * (2 * n), n, func, default

    def fill(self, arr):
        self.tree[self.n:] = arr
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.func(self.tree[i << 1], self.tree[(i << 1) + 1])

    # get interval[l,r)
    def query(self, l, r):
        res = self.default
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                res = self.func(res, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                res = self.func(res, self.tree[r])
            l >>= 1
            r >>= 1

        return res

    def __setitem__(self, ix, val):
        ix += self.n
        self.tree[ix] = val

        while ix > 1:
            self.tree[ix >> 1] = self.func(self.tree[ix], self.tree[ix ^ 1])
            ix >>= 1

    def __getitem__(self, item):
        return self.tree[item + self.n]


input = lambda: sys.stdin.buffer.readline().decode().strip()
n, m = map(int, input().split())
a, mi, ma, lst = [int(x) - 1 for x in input().split()], list(range(1, n + 1)), list(range(1, n + 1)), [-1] * n
tree = segmenttree(m + n)

for i in range(m):
    mi[a[i]] = 1
    if lst[a[i]] != -1:
        ma[a[i]] = max(ma[a[i]], tree.query(lst[a[i]], i))
        tree[lst[a[i]]] = 0
    else:
        ma[a[i]] += tree.query(m + a[i] + 1, n + m)

    tree[a[i] + m] = tree[i] = 1
    lst[a[i]] = i

for i in range(n):
    if lst[i] == -1:
        ma[i] += tree.query(m + i + 1, n + m)
    else:
        ma[i] = max(ma[i], tree.query(lst[i], m))

print('\n'.join([f'{mi[i]} {ma[i]}' for i in range(n)]))
