import sys
from array import array
from bisect import *

input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
tests, Mint, Mlong = 1, 2 ** 31 - 1, 2 ** 63 - 1
out = []
max_ = 10 ** 6 + 1


class range_sum:
    def __init__(self, n, default, func):
        self.tree, self.n, self.lazy, self.h = [0] * (2 * n), n, [0] * (n), 20
        self.default, self.func = default, func

    def apply(self, p, val):
        self.tree[p] += val
        if p < self.n:
            self.lazy[p] += val

    # fix applied nodes and down nodes
    def build(self, p):
        while p > 1:
            p >>= 1
            self.tree[p] = self.func(self.tree[p << 1], self.tree[(p << 1) + 1]) + self.lazy[p]

    # push lazy operations
    def push(self, p):
        for s in range(self.h, 0, -1):
            i = p >> s
            if self.lazy[i]:
                self.apply(i * 2, self.lazy[i])
                self.apply(i * 2 + 1, self.lazy[i])
                self.lazy[i] = 0

    def update(self, l, r, val):
        '''[l,r)'''
        l += self.n
        r += self.n
        l0, r0 = l, r

        while l < r:
            if l & 1:
                self.apply(l, val)
                l += 1

            if r & 1:
                r -= 1
                self.apply(r, val)

            l >>= 1
            r >>= 1

        self.build(l0)
        self.build(r0 - 1)

    def query(self, l, r):
        '''[l,r)'''
        l += self.n
        r += self.n

        # apply lazy nodes
        self.push(l)
        self.push(r - 1)
        res = self.default

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


for _ in range(tests):
    n, m, p = inp(int)
    att = array('i', [Mint] * max_)
    def_ = array('i', [Mint] * max_)
    mdef = array('i', [-1] * p)
    matt = array('i', [-1] * p)
    mcoin = array('i', [-1] * p)
    adj = [array('i') for _ in range(max_)]
    defs = array('i')
    tree = range_sum(m, -Mint, max)

    for i in range(n):
        a, ca = inp(int)
        att[a] = min(att[a], ca)

    for i in range(m):
        b, cb = inp(int)
        def_[b] = min(def_[b], cb)

    for i in range(p):
        mdef[i], matt[i], mcoin[i] = inp(int)
        adj[mdef[i]].append(i)

    for i in range(max_):
        if def_[i] != Mint:
            defs.append(i)
            tree.update(len(defs) - 1, len(defs), -def_[i])

    ans = -Mlong
    for i in range(max_):
        if att[i] != Mint:
            ans = max(ans, tree.query(0, len(defs)) - att[i])

        for j in adj[i]:
            ix = bisect_right(defs, matt[j])
            if ix < len(defs): tree.update(ix, len(defs), mcoin[j])

    out.append(ans)
print('\n'.join(map(str, out)))
