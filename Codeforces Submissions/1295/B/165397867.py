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


for _ in range(int(input())):
    # n=int(input())
    n, k=map(int, input().split())
    s=input()
    l1=[0]*(n+1)
    for i in range(1, n+1):
        if s[i-1]=="0":
            l1[i]=l1[i-1]+1
        else:
            l1[i]=l1[i-1]-1


    if l1[-1]==0:
        if k in l1:
            print(-1)
        else:
            print(0)
    else:
        ans=0
        netval=l1[-1]

        d1={}
        for i in l1[:len(l1)-1]:
            d1[i]=d1.get(i, 0)+1
        # print(netval, d1, l1)

        for key in d1:
            t=(k-key)
            if t*netval>=0 and t%netval==0:
                ans+=d1[key]
        print(ans)