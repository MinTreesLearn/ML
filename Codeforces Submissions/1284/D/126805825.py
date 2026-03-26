import heapq
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


n = int(input())
A = [None]*n
B = [None]*n

events = dict()
events0 = dict()
for i in range(n):
    sa,ea,sb,eb = map(int,input().split())
    if sa not in events:
        events[sa] = [[],[]]
    if ea not in events:
        events[ea] = [[],[]]

    if sb not in events0:
        events0[sb] = [[],[]]
    if eb not in events0:
        events0[eb] = [[],[]]

    events[sa][1].append(i)
    events[ea][0].append(i)
    events0[sb][1].append(i)
    events0[eb][0].append(i)

    A[i] = (sa,ea)
    B[i] = (sb,eb)

I = list(range(n))
I.sort(key=lambda i: A[i])
lo,hi = [],[]

to_remove_lo = {x:0 for x,_ in B}
to_remove_hi = {x:0 for _,x in B}

for t in sorted(events):
    for i in events[t][1]:
        sb,eb = B[i]
        heapq.heappush(lo, -sb)
        heapq.heappush(hi, eb)

    while lo and to_remove_lo[-lo[0]]:
        to_remove_lo[-heapq.heappop(lo)] -= 1

    while hi and to_remove_hi[hi[0]]:
        to_remove_hi[heapq.heappop(hi)] -= 1

    # check
    if -lo[0] > hi[0]:
        print("NO")
        exit()

    for i in events[t][0]:
        sb,eb = B[i]

        to_remove_lo[sb] += 1
        to_remove_hi[eb] += 1


I = list(range(n))
I.sort(key=lambda i: B[i])
lo,hi = [],[]

to_remove_lo = {x:0 for x,_ in A}
to_remove_hi = {x:0 for _,x in A}

for t in sorted(events0):
    for i in events0[t][1]:
        sa,ea = A[i]
        heapq.heappush(lo, -sa)
        heapq.heappush(hi, ea)

    while lo and to_remove_lo[-lo[0]]:
        to_remove_lo[-heapq.heappop(lo)] -= 1

    while hi and to_remove_hi[hi[0]]:
        to_remove_hi[heapq.heappop(hi)] -= 1

    # check
    if -lo[0] > hi[0]:
        print("NO")
        exit()

    for i in events0[t][0]:
        sa,ea = A[i]

        to_remove_lo[sa] += 1
        to_remove_hi[ea] += 1

print("YES")
