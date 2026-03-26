#Don't stalk me, don't stop me, from making submissions at high speed. If you don't trust me,
import sys
#then trust me, don't waste your time not trusting me. I don't plagiarise, don't fantasize,
import os
#just let my hard work synthesize my rating. Don't be sad, just try again, everyone fails
from io import BytesIO, IOBase
BUFSIZE = 8192
#every now and then. Just keep coding, just keep working and you'll keep progressing at speed-
# -forcing.
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
#code by _Frust(CF)/Frust(AtCoder)
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
    input = lambda: sys.stdin.readline().rstrip("\r\n")
import math
import heapq as hq



def bfs(d):
    qu=[[d, 0]]
    sp[d]=[0, 1]
    s1=set([d])

    while qu:
        ele, dist=qu.pop(0)

        for i in adj[ele]:
            if i not in s1:
                qu.append([i, dist+1])
                sp[i]=[dist+1, set([ele])]
                s1.add(i)
            else:
                if sp[i][0]==dist+1:
                    sp[i][1].add(ele)

                elif sp[i][0]>dist+1:
                    sp[i]=[dist+1, set([ele])]
    return


n, m=map(int, input().split())

adj=[[] for i in range(n+1)]
adj1=[[] for i in range(n+1)]
for i in range(m):
    a, b=map(int, input().split())
    adj1[a].append(b)
    adj[b].append(a)

# for i in range(1, n+1):
#     print(i, ":", adj1[i])

k=int(input())
li=[int(i) for i in input().split()]

dest=li[-1]
inf=n+1
sp=[[inf, inf] for i in range(n+1)]

bfs(dest)
best=worst=0

# for i in range(1, n+1):
#     # print(i, ":", sp[i])

for i in range(k-1):
    p=li[i]
    currd=(k-i-1)

    if li[i+1] in sp[p][1]:
        best=best
        if len(sp[p][1])>1:
            worst+=1
    else:
        best+=1
        worst+=1
print(best, worst)
