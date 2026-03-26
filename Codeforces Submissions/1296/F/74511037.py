import sys

class RangeMinQuery:
    # O(nlog(n)) construction/space, O(1) range minimum query
    def __init__(self, data):
        self._data = [list(data)]
        n = len(self._data[0])

        # self._data[i][j] stores the min of the segment [j, j + 2 ** i] where i is in [1,2,4,8,...,log(N)]
        w = 1
        while 2 * w <= n:
            prev = self._data[-1]
            self._data.append([min(prev[j], prev[j + w]) for j in range(n - 2 * w + 1)])
            w *= 2

    def query(self, begin, end):
        # Find min of [begin, end)
        # Take the min of the overlapping intervals [begin, begin + 2**depth) and [end - 2**depth, end)
        assert begin < end
        depth = (end - begin).bit_length() - 1
        return min(self._data[depth][begin], self._data[depth][end - (1 << depth)])


class LCA:
    def __init__(self, graph, root=1):
        # Euler tour representation recording every visit to each node in the DFS
        self.eulerTour = []
        # For each node record the index of their first visit in the euler tour
        self.preorder = [None] * len(graph)
        # Record last visit
        self.postorder = [None] * len(graph)
        # Depth of each node to the root
        self.depth = [None] * len(graph)
        # Parent of each node
        self.parent = [None] * len(graph)

        # DFS
        stack = [root]
        self.depth[root] = 0
        self.parent[root] = None
        while stack:
            node = stack.pop()
            # Record a visit in the euler tour
            self.eulerTour.append(node)
            if self.preorder[node] is None:
                # Record first visit
                self.preorder[node] = len(self.eulerTour) - 1

                for nbr in graph[node]:
                    if self.preorder[nbr] is None:
                        self.depth[nbr] = self.depth[node] + 1
                        self.parent[nbr] = node
                        stack.append(node)
                        stack.append(nbr)
            # Record last visit (this can be overwritten)
            self.postorder[node] = len(self.eulerTour) - 1

        # self.rmq = RangeMinQuery(self.preorder[node] for node in self.eulerTour)

        if False:
            # Check invariants

            assert self.depth[1] == 0
            assert self.parent[1] == None
            for node in range(1, len(graph)):
                assert self.preorder[node] == self.eulerTour.index(node)
                assert self.postorder[node] == max(
                    i for i, x in enumerate(self.eulerTour) if x == node
                )

            for i in range(len(self.rmq._data)):
                for j in range(i + 1, len(self.rmq._data) + 1):
                    assert min(self.rmq._data[0][i:j]) == self.rmq.query(i, j)

            for u in range(1, N + 1):
                for v in range(1, N + 1):
                    assert self.lca(u, v) == self.lca(v, u)
                    lca = self.lca(u, v)
                    assert self.isAncestor(lca, u)
                    assert self.isAncestor(lca, v)
                    path = self.path(u, v)
                    assert len(path) == self.dist(u, v) + 1
                    for x, y in zip(path, path[1:]):
                        assert y in graph[x]
                    assert len(set(path)) == len(path)

    def lca(self, u, v):
        a = self.preorder[u]
        b = self.preorder[v]
        if a > b:
            a, b = b, a
        return self.eulerTour[self.rmq.query(a, b + 1)]

    def dist(self, u, v):
        return self.depth[u] + self.depth[v] - 2 * self.depth[self.lca(u, v)]

    def isAncestor(self, ancestor, v):
        # Checks if `ancestor` is an ancestor of `v`
        return (
            self.preorder[ancestor] <= self.preorder[v]
            and self.postorder[v] <= self.postorder[ancestor]
        )

    def path(self, u, v):
        # Returns the path from u to v in the tree. This doesn't rely on rmq
        # Walk up from u until u becomes ancestor of v (the LCA)
        uPath = []
        while not self.isAncestor(u, v):
            uPath.append(u)
            u = self.parent[u]
        lca = u
        # Walk up from v until v is at the LCA too
        assert self.isAncestor(u, v)
        vPath = []
        while v != lca:
            vPath.append(v)
            v = self.parent[v]
        ret = uPath + [lca] + vPath[::-1]
        return ret


def solve(N, edges, passengers):
    graph = [[] for i in range(N + 1)]
    for e in edges:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])

    tree = LCA(graph)

    scores = [[1 for j in range(N + 1)] for i in range(N + 1)]
    for a, b, score in passengers:
        path = tree.path(a, b)
        assert path[0] == a and path[-1] == b
        for u, v in zip(path, path[1:]):
            scores[u][v] = max(scores[u][v], score)
            scores[v][u] = max(scores[v][u], score)

    for a, b, score in passengers:
        ans = float("inf")
        path = tree.path(a, b)
        for u, v in zip(path, path[1:]):
            ans = min(ans, scores[u][v])
        if ans != score:
            return -1

    return " ".join(str(scores[e[0]][e[1]]) for e in edges)


if False:
    N = 5000
    edges = list(zip(range(N - 1), range(1, N)))
    assert len(edges) == N - 1
    passengers = [(0, p, N - p) for p in range(1, N)]
    solve(N, edges, passengers)
    exit(0)

if __name__ == "__main__":
    input = sys.stdin.readline

    N = int(input())
    edges = [[int(x) for x in input().split()] for i in range(N - 1)]
    P = int(input())
    passengers = [[int(x) for x in input().split()] for i in range(P)]

    ans = solve(N, edges, passengers)
    print(ans)
