import sys
from array import array
from bisect import *

input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
out, tests = [], 1
max_ = 10 ** 6 + 1


class range_sum:
    def __init__(self, n, default):
        self.tree, self.n, self.lazy, self.h = [0] * (2 * n), n, [0] * (n), 20
        self.default = default

    def apply(self, p, val):
        self.tree[p] += val
        if p < self.n:
            self.lazy[p] += val

    # fix applied nodes and down nodes
    def build(self, p):
        children = 1
        while p > 1:
            p >>= 1
            children <<= 1
            self.tree[p] = max(self.tree[p << 1], self.tree[(p << 1) + 1]) + self.lazy[p]

    # push lazy operations
    def push(self, p):
        for s in range(self.h, 0, -1):
            i = p >> s
            if self.lazy[i]:
                children = 1 << (s - 1)
                self.apply(i * 2, self.lazy[i])
                self.apply(i * 2 + 1, self.lazy[i])
                self.lazy[i] = 0

    def update(self, l, r, val):
        '''[l,r)'''
        l += self.n
        r += self.n
        l0, r0, children = l, r, 1

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
                res = max(res, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                res = max(res, self.tree[r])

            l >>= 1
            r >>= 1
        return res


for _ in range(tests):
    n, m, p = inp(int)
    att = array('i', [10 ** 9 + 1] * max_)
    def_ = array('i', [10 ** 9 + 1] * max_)
    mdef = array('i', [-1] * p)
    matt = array('i', [-1] * p)
    mcoin = array('i', [-1] * p)
    adj = [array('i') for _ in range(max_)]
    defs = array('i')
    tree = range_sum(m, -10 ** 9)

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
        if def_[i] != 10 ** 9 + 1:
            defs.append(i)
            tree.update(len(defs) - 1, len(defs), -def_[i])

    ans = -10 ** 18
    for i in range(max_):
        if att[i] != 10 ** 9 + 1:
            ans = max(ans, tree.query(0, len(defs)) - att[i])

        for j in adj[i]:
            ix = bisect_right(defs, matt[j])
            if ix < len(defs): tree.update(ix, len(defs), mcoin[j])

    out.append(ans)
print('\n'.join(map(str, out)))
