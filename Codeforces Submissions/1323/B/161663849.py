import sys
import os
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

def fctrs(n):
    import math
    res=[1, n]
    for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
            res.append(i)
            if i!=(n//i):
                res.append(n//i)
    return res



def cons(arr):
    s=0
    res=[0]*(1+len(arr))
    for i in range(len(arr)):
        if arr[i]==1:
            s+=1
        else:
            s=0
        res[s]+=1
        
    s=0
    for i in range(len(arr), -1, -1):
        res[i]+=s
        s=res[i]
    return res
        


n, m, k=map(int, input().split())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]

bcons=cons(b)
acons=cons(a)

# print(acons)
# print(bcons)
ans=0
for i in range(1, len(bcons)):
    if k%i==0:
        c=(k//i)
        a1=(acons[c] if c<len(acons) else 0)
        b1=bcons[i]
        # print(i, c, a1, b1)
        ans+=a1*b1
print(ans)