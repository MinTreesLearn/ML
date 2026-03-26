import os, sys
from io import BytesIO, IOBase
from collections import *


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


class graph:
    def __init__(self, n):
        self.n, self.gdict = n, [[] for _ in range(n + 1)]

    def addEdge(self, node1, node2):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)

    def subtree(self, v):
        queue, visit, child = deque([v]), [False] * (n + 1), []
        visit[v], ma, parent, maxes = True, [0] * (n + 1), [-1] * (n + 1), [[-10 ** 9, 0] for _ in range(n + 1)]

        while queue:
            s = queue.popleft()

            for i1 in self.gdict[s]:
                if not visit[i1]:
                    queue.append(i1)
                    visit[i1] = True
                    child.append(i1)
                    parent[i1] = s

        for i in child[::-1]:
            ma[parent[i]] = max(ma[i] + 1, ma[parent[i]])
            maxes[parent[i]].append(ma[i] + 1)

        for i in range(1, n + 1):
            maxes[i] = sorted(maxes[i])[-3:]

        for i in child:
            new = -1
            if maxes[parent[i]][-1] == ma[i] + 1:
                new = -2

            maxes[i].append(maxes[parent[i]][new] + 1)
            maxes[i] = sorted(maxes[i])[-3:]
            ma[i] = max(ma[i], maxes[parent[i]][new] + 1)

        tem = [sum(x) for x in maxes]
        ix, ans, su = max(range(n + 1), key=tem.__getitem__), [], 0
        visit[ix], mem = False, [() for _ in range(n + 1)]

        for i in self.gdict[ix]:
            queue.append((i, 1))
            visit[i], parent[i] = False, i

        while queue:
            s, lev = queue.popleft()
            flag = 1

            for i1 in self.gdict[s]:
                if visit[i1]:
                    queue.append((i1, lev + 1))
                    visit[i1], flag, parent[i1] = False, 0, parent[s]

            if flag:
                mem[parent[s]] = (lev, s)

        mem.sort()
        for i in range(n, n - 3, -1):
            if not mem[i]:
                break
            ans.append(mem[i][1])
            su += mem[i][0]

        if len(ans) < 3:
            ans.append(ix)
        print(su, '\n', *ans)


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp(dtype) for _ in range(n)]
inp_enu = lambda dtype: [(i, x) for i, x in enumerate(inp(dtype))]
inp_enus = lambda dtype, n: [[i] + inp(dtype) for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

n = int(input())
g = graph(n)
for _ in range(n - 1):
    u, v = inp(int)
    g.addEdge(u, v)
g.subtree(1)
