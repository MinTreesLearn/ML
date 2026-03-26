import os, sys
from io import BytesIO, IOBase
from array import array
from itertools import accumulate
import bisect
import math
from collections import deque

# from functools import cache
# cache cf需要自己提交 pypy3.9!
from copy import deepcopy


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().strip()
ints = lambda: list(map(int, input().split()))
Int = lambda: int(input())


def queryInteractive(a, b, c):
    print('? {} {} {}'.format(a, b, c))
    sys.stdout.flush()
    return int(input())


def answerInteractive(x1, x2):
    print('! {} {}'.format(x1, x2))
    sys.stdout.flush()



#不需要parent
class LCA:
    """<O(n), O(log(n))>"""

    def __init__(self, G, root):
        from collections import deque

        self.n = len(G)
        self.tour = [0] * (2 * self.n - 1)
        self.depth_list = [0] * (2 * self.n - 1)
        self.id = [-1] * self.n
        parents = self.gen_par(G, root)
        self.dfs(G, root, parents)
        self._rmq_init(self.depth_list)

    def _rmq_init(self, arr):
        n = self.mod = len(arr)
        self.seg_len = 1 << (n - 1).bit_length()
        self.seg = [self.n * n] * (2 * self.seg_len)
        seg = self.seg
        for i, e in enumerate(arr):
            seg[self.seg_len + i] = n * e + i
        for i in range(self.seg_len - 1, 0, -1):
            seg[i] = min(seg[2 * i], seg[2 * i + 1])

    def _rmq_query(self, l, r):
        l += self.seg_len
        r += self.seg_len
        res = self.n * self.mod
        seg = self.seg
        while l < r:
            if r & 1:
                r -= 1
                res = min(res, seg[r])
            if l & 1:
                res = min(res, seg[l])
                l += 1
            l >>= 1
            r >>= 1
        return res % self.mod

    def gen_par(self, G, root):
        par = [-1] * self.n
        q = deque([root])
        vis = [0] * self.n
        vis[root] = 1
        while q:
            x = q.pop()
            for y in G[x]:
                if vis[y] == 0:
                    vis[y] = 1
                    q.append(y)
                    par[y] = x
        return par

    def dfs(self, G, root, parents):
        id = self.id
        tour = self.tour
        depth_list = self.depth_list
        v = root
        it = [0] * self.n
        visit_id = 0
        depth = 0
        while v != -1:
            if id[v] == -1:
                id[v] = visit_id
            tour[visit_id] = v
            depth_list[visit_id] = depth
            visit_id += 1
            g = G[v]
            if it[v] == len(g):
                v = parents[v]
                depth -= 1
                continue
            if g[it[v]] == parents[v]:
                it[v] += 1
                if it[v] == len(g):
                    v = parents[v]
                    depth -= 1
                    continue
                else:
                    child = g[it[v]]
                    it[v] += 1
                    v = child
                    depth += 1
            else:
                child = g[it[v]]
                it[v] += 1
                v = child
                depth += 1

    def lca(self, u: int, v: int) -> int:
        l, r = self.id[u], self.id[v]
        if r < l:
            l, r = r, l
        q = self._rmq_query(l, r + 1)
        return self.tour[q]

    def dist(self, u: int, v: int) -> int:
        lca = self.lca(u, v)
        depth_u = self.depth_list[self.id[u]]
        depth_v = self.depth_list[self.id[v]]
        depth_lca = self.depth_list[self.id[lca]]
        return depth_u + depth_v - 2 * depth_lca



inf = float('inf')
n = Int()
g = [[] for _ in range(n)]

for _ in range(n-1):
    a,b = ints()
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

lca = LCA(g,0)
q = Int()
for _ in range(q):
    x,y,a,b,k = ints()
    x -= 1
    y -= 1
    a -= 1
    b -= 1
    
    d1 = lca.dist(a,b)
    d2 = lca.dist(a,y) + lca.dist(b,x) + 1
    d3 = lca.dist(a,x) + lca.dist(b,y) + 1
    flag = 1
    for d in [d1,d2,d3]:
        if d <= k and (k - d)%2 == 0:
            print("YES")
            flag = 0
            break
    if flag:
        print("NO")

        

