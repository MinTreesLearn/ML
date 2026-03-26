import sys
from array import array
from collections import deque

input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
out, tests = [], 1


class graph:
    def __init__(self, n):
        self.n = n
        self.gdict = [array('i') for _ in range(n + 1)]

    def add_edge(self, node1, node2):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)

    def bfs_util(self, root):
        visit, self.dist = array('b', [0] * (self.n + 1)), [0] * (self.n + 1)
        queue, visit[root] = deque([root]), True

        while queue:
            s = queue.popleft()
            for i1 in self.gdict[s]:
                if visit[i1] == False:
                    queue.append(i1)
                    visit[i1], self.dist[i1] = True, self.dist[s] + 1
        return self.dist


for _ in range(tests):
    n, m, k = inp(int)
    sp = array('i', inp(int))
    g, ans = graph(n), 0

    for i in range(m):
        u, v = inp(int)
        g.add_edge(u, v)

    dist1 = g.bfs_util(1)
    distn = g.bfs_util(n)
    sor = array('i', sorted(range(k), key=lambda x: dist1[sp[x]] - distn[sp[x]]))
    suf = array('i', [0])

    for i in sor[::-1]:
        suf.append(max(suf[-1], distn[sp[i]]))

    suf.reverse()
    for ix in range(k - 1):
        i = sor[ix]
        ans = max(ans, suf[ix + 1] + dist1[sp[i]] + 1)

    out.append(min(ans, dist1[n]))
print('\n'.join(map(str, out)))
