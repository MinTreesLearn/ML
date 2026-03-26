class HLD:
    def __init__(self, g):
        self.g = g
        self.n = len(g)
        self.parent = [-1]*self.n
        self.size = [1]*self.n
        self.head = [0]*self.n
        self.preorder = [0]*self.n
        self.k = 0
        self.depth = [0]*self.n

        for v in range(self.n):
            if self.parent[v] == -1:
                self.dfs_pre(v)
                self.dfs_hld(v)

    def dfs_pre(self, v):
        g = self.g
        stack = [v]
        order = [v]
        while stack:
            v = stack.pop()
            for u in g[v]:
                if self.parent[v] == u:
                    continue
                self.parent[u] = v
                self.depth[u] = self.depth[v]+1
                stack.append(u)
                order.append(u)

        # 隣接リストの左端: heavyな頂点への辺
        # 隣接リストの右端: 親への辺
        while order:
            v = order.pop()
            child_v = g[v]
            if len(child_v) and child_v[0] == self.parent[v]:
                child_v[0], child_v[-1] = child_v[-1], child_v[0]
            for i, u in enumerate(child_v):
                if u == self.parent[v]:
                    continue
                self.size[v] += self.size[u]
                if self.size[u] > self.size[child_v[0]]:
                    child_v[i], child_v[0] = child_v[0], child_v[i]

    def dfs_hld(self, v):
        stack = [v]
        while stack:
            v = stack.pop()
            self.preorder[v] = self.k
            self.k += 1
            top = self.g[v][0]
            # 隣接リストを逆順に見ていく（親 > lightな頂点への辺 > heavyな頂点 (top)）
            # 連結成分が連続するようにならべる
            for u in reversed(self.g[v]):
                if u == self.parent[v]:
                    continue
                if u == top:
                    self.head[u] = self.head[v]
                else:
                    self.head[u] = u
                stack.append(u)

    def for_each(self, u, v):
        # [u, v]上の頂点集合の区間を列挙
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            l = max(self.preorder[self.head[v]], self.preorder[u])
            r = self.preorder[v]
            yield l, r # [l, r]
            if self.head[u] != self.head[v]:
                v = self.parent[self.head[v]]
            else:
                return

    def for_each_edge(self, u, v):
        # [u, v]上の辺集合の区間列挙
        # 辺の情報は子の頂点に
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            if self.head[u] != self.head[v]:
                yield self.preorder[self.head[v]], self.preorder[v]
                v = self.parent[self.head[v]]
            else:
                if u != v:
                    yield self.preorder[u]+1, self.preorder[v]
                break

    def subtree(self, v):
        # 頂点vの部分木の頂点集合の区間 [l, r)
        l = self.preorder[v]
        r = self.preorder[v]+self.size[v]
        return l, r

    def lca(self, u, v):
        # 頂点u, vのLCA
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            if self.head[u] == self.head[v]:
                return u
            v = self.parent[self.head[v]]

class SegTree:
    def __init__(self, init_val, ide_ele, segfunc):
        self.n = len(init_val)
        self.num = 2**(self.n-1).bit_length()
        self.ide_ele = ide_ele
        self.segfunc = segfunc
        self.seg = [ide_ele]*2*self.num
        # set_val
        for i in range(self.n):
            self.seg[i+self.num] = init_val[i]
        # built
        for i in range(self.num-1, 0, -1):
            self.seg[i] = self.segfunc(self.seg[2*i], self.seg[2*i+1])

    def update(self, k, x):
        k += self.num
        self.seg[k] = x
        while k:
            k = k >> 1
            self.seg[k] = self.segfunc(self.seg[2*k], self.seg[2*k+1])

    def query(self, l, r):
        if r <= l:
            return self.ide_ele
        l += self.num
        r += self.num
        lres = self.ide_ele
        rres = self.ide_ele
        while l < r:
            if r & 1:
                r -= 1
                rres = self.segfunc(self.seg[r], rres)
            if l & 1:
                lres = self.segfunc(lres, self.seg[l])
                l += 1
            l = l >> 1
            r = r >> 1
        res = self.segfunc(lres, rres)
        return res

    def __str__(self): # for debug
        arr = [self.query(i,i+1) for i in range(self.n)]
        return str(arr)

import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

INF = 10**6

n = int(input())
edge = [[] for i in range(n)]
toid = {}
for i in range(n-1):
    x, y = map(int, input().split())
    x, y =x-1, y-1
    edge[x].append(y)
    edge[y].append(x)
    toid[(x,y)] = i
    toid[(y,x)] = i

m = int(input())
Q = []
for i in range(m):
    a, b, g = map(int, input().split())
    a, b = a-1, b-1
    Q.append((a, b, g))
Q.sort(key=lambda x: -x[2])
hld = HLD(edge)
segMin = SegTree([INF]*n, INF, min)
segPos = SegTree(list(range(n)), -1, max)
for a, b, g in Q:
    for l, r in hld.for_each_edge(a, b):
        while segPos.query(l, r+1) != -1:
            p = segPos.query(l, r+1)
            segMin.update(p, g)
            segPos.update(p, -1)
    check = INF
    for l, r in hld.for_each_edge(a, b):
        check = min(check, segMin.query(l, r+1))
    if check != g:
        print(-1)
        exit()
ans = [0]*(n-1)
for v in range(1, n):
    i = hld.preorder[v]
    p = hld.parent[v]
    idx = toid[(p, v)]
    f = segMin.query(i, i+1)
    ans[idx] = f
print(*ans)
