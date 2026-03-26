import sys
from collections import deque


class graph:
    def __init__(self, n):
        self.n, self.gdict = n, [[] for _ in range(n + 1)]
        self.l = [0] * (n + 1)

    def addEdge(self, node1, node2, w=None):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)
        self.l[node1] += 1
        self.l[node2] += 1

    def kahn(self):
        que, cnt = deque([i for i in range(1, self.n + 1) if self.l[i] == 1]), 0

        while len(que) >= 2:
            s1, s2 = que.popleft(), que.popleft()
            for i in self.gdict[s1]:
                self.l[i] -= 1
                if self.l[i] == 1:
                    que.append(i)

            for i in self.gdict[s2]:
                self.l[i] -= 1
                if self.l[i] == 1:
                    que.append(i)

            lca = ask(f'? {s1} {s2}')
            if lca in (s1, s2):
                print(f'! {lca}', flush=True)
                break

        else:
            print(f'! {que.popleft()}', flush=True)


def ask(q):
    print(q, flush=True)
    return int(input())


input = lambda: sys.stdin.buffer.readline().decode().strip()
n = int(input())
g = graph(n)
for _ in range(n - 1):
    u, v = map(int, input().split())
    g.addEdge(u, v)
g.kahn()
