import sys
from array import array
from collections import deque

input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
Mint, Mlong = 2 ** 31 - 1, 2 ** 63 - 1
out, tests = [], 1


class graph:
    def __init__(self, n):
        self.n = n
        self.gdict = [array('i') for _ in range(n + 1)]

    def add_edge(self, node1, node2):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)

    def subtree(self, root):
        queue, visit = deque([root]), array('b', [0] * (self.n + 1))
        self.level, child = array('i', [0] * (self.n + 1)), array('i')
        self.par, visit[root] = array('i', [-1] * (self.n + 1)), True

        while queue:
            s = queue.popleft()

            for i1 in self.gdict[s]:
                if not visit[i1]:
                    queue.append(i1)
                    visit[i1], self.level[i1] = True, self.level[s] + 1
                    child.append(i1)
                    self.par[i1] = s

    def lca_preprocess(self, root):
        self.subtree(root)
        self.lev = 21
        self.table = [array('i', [-1] * (self.n + 1)) for _ in range(self.lev)]
        self.table[0] = self.par

        for i in range(1, self.lev):
            for node in range(1, self.n + 1):
                if self.table[i - 1][node] != -1:
                    self.table[i][node] = self.table[i - 1][self.table[i - 1][node]]

    def lca(self, u, v):
        if self.level[v] < self.level[u]:
            u, v = v, u
        diff = self.level[v] - self.level[u]

        for i in range(self.lev):
            if (diff >> i) & 1:
                v = self.table[i][v]

        if u == v:
            return u

        for i in range(self.lev - 1, -1, -1):
            if self.table[i][u] != self.table[i][v]:
                u, v = self.table[i][u], self.table[i][v]

        return self.table[0][u]


def get_dist(u, v):
    return g.level[u] + g.level[v] - g.level[g.lca(u, v)] * 2


for _ in range(tests):
    n = int(input())
    g = graph(n)
    for i in range(n - 1):
        u, v = inp(int)
        g.add_edge(u, v)

    g.lca_preprocess(1)
    for i in range(int(input())):
        x, y, a, b, k = inp(int)
        dists = [get_dist(a, b), get_dist(a, x) + 1 + get_dist(y, b), get_dist(a, y) + 1 + get_dist(x, b)]
        ans = 0
        for d in dists: ans |= d <= k and (k - d) & 1 == 0
        out.append(['no', 'yes'][ans])

print('\n'.join(map(str, out)))
