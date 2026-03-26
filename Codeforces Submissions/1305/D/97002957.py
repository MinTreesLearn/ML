# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def main():
    n = int(input())
    path = [set() for _ in range(n+1)]
    for _ in range(n-1):
        u1,v1 = map(int,input().split())
        path[u1].add(v1)
        path[v1].add(u1)
    ini = n
    while 1:
        if not len(path[ini]):
            print('!',ini)
            exit()
        elif len(path[ini]) == 1:
            x = path[ini].pop()
            path[x].remove(ini)
            if len(path[x]):
                y = path[x].pop()
                path[y].remove(x)
                print('?',y,ini)
                sys.stdout.flush()
            else:
                print('?',x,ini)
                sys.stdout.flush()
            w = int(input())
            ini = w
        else:
            x,y = path[ini].pop(),path[ini].pop()
            print('?',x,y)
            sys.stdout.flush()
            path[x].remove(ini)
            path[y].remove(ini)
            w = int(input())
            if w != ini:
                ini = w

#Fast IO Region
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

if __name__ == '__main__':
    main()