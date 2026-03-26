from sys import stdin, gettrace, stdout

# if not gettrace():
#     def input():
#         return next(stdin)[:-1]
#

def main():
    n = int(input())
    aa = [int(a) for a in input().split()]
    sum = [0]
    for a in aa:
        sum.append(sum[-1] + a)
    def mean(i,j):
        return (sum[j] - sum[i])/(j - i)
    stk = []
    for i in range(n):
        stk.append((i, i+1))
        while len(stk) > 1 and mean(*stk[-2]) >= mean(*stk[-1]):
            _, j = stk.pop()
            i, _ = stk.pop()
            stk.append((i, j))
    for i,j in stk:
        v = str(mean(i,j))+'\n'
        for k in range(j-i):
            stdout.write(v)

if __name__ == "__main__":
    main()

# https://github.com/cheran-senthil/PyRival/blob/master/templates/template_py3.py
import os
import sys
from io import BytesIO, IOBase

# region fastio

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

# endregion
