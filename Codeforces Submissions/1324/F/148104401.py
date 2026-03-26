# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
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
input = lambda: sys.stdin.readline().rstrip("\r\n")
# ------------------- fast io --------------------

from collections import defaultdict
from types import GeneratorType
import sys
sys.setrecursionlimit(200001)

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc



def main():
    @bootstrap
    def dfs(u, fa):
        par[u] = fa
        dp[u] = 1 if a[u-1] == 1 else -1
        for v in adj[u]:
            if v != fa:
                yield dfs(v, u)
                if dp[v] > 0:
                    dp[u] += dp[v]
        yield
    
    @bootstrap
    def dfs2(u, fa):
        par[u] = fa
        for v in adj[u]:
            if v != fa:
                if res[u] > dp[v]:
                    if dp[v] < 0:
                        res[v] = res[u] + dp[v]
                    else:
                        res[v] = res[u]
                else:
                    res[v] = dp[v]
                yield dfs2(v, u)
        yield
        
    n = int(input())
    a = list(map(int, input().split(' ')))
    adj = defaultdict(list)
    for i in range(n - 1):
        u, v = map(int, input().split(' '))
        adj[u].append(v)
        adj[v].append(u)
    dp = [0] * (n + 1)
    par = [0] * (n + 1)
    res = [0] * (n + 1)
    dfs(1, 0)
    res[1] = dp[1]
    dfs2(1, 0)
    print(*res[1:])
    
main()