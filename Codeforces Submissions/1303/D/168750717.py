import os, sys
from io import BytesIO, IOBase
from array import array


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


inf = float('inf')

pow2 = [1]
for _ in range(30):
    pow2.append(2 * pow2[-1])
dic = {pow2[i]:i for i in range(30)}


T = Int()
while T:
    T -= 1
    n, m = ints()
    arr = ints()
    if sum(arr) < n:
        print(-1)
        continue
    
    l = [0] * 61
    for x in arr:
        l[dic[x]] += 1
    ans = 0
    i = 0
    while i < 60:
        if (n>>i)&1:
            if l[i] > 0:
                l[i] -= 1
            else:
                while l[i] == 0:
                    i += 1
                    ans += 1
                l[i] -= 1
                continue
        l[i+1] += l[i]//2
        i += 1            
    print(ans)
    
    
