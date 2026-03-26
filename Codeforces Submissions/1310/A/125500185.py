import os,sys
from io import BytesIO, IOBase
from heapq import *
 
def main():
    n = int(input())
    lst = [(a,b)for a,b in zip(map(int,input().split()),map(int,input().split()))]
    lst.sort(key=lambda xx:xx[0])
    heap = []
    i,ans,su = 0,0,0
    while i != n:
        j,st = i,lst[max(0,i-1)][0]
        ans += su*(lst[i][0]-st)
        for x in range(lst[i][0]-st):
            if not len(heap):
                break
            r = heappop(heap)
            su += r
            ans += r*(lst[i][0]-x-st)
        while i != n and lst[i][0] == lst[j][0]:
            su += lst[i][1]
            heappush(heap,-lst[i][1])
            i += 1
    cou = 0
    while len(heap):
        ans -= cou*heappop(heap)
        cou += 1
    print(ans)
 
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