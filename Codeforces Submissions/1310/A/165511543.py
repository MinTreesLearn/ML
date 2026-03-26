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



n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]

d1={} 
for i in range(n):
    if a[i] in d1:
        d1[a[i]].append(b[i])
    else:
        d1[a[i]]=[b[i]]
# print(d1)

eles=sorted(d1.keys())
n=len(eles)
arr=[]
total=0
added=False
ch=0
ans=0
while ch<n:
    # print(ch, arr)
    if len(d1[eles[ch]])>1 or added:
        temp=sorted(d1[eles[ch]])
        for i in temp:
            total+=i
            hq.heappush(arr, -i)
        # print(ch, arr)
        maxi=hq.heappop(arr)*(-1)
        d1[eles[ch]]=[maxi]
        total-=maxi
        curr=eles[ch]+1
        # print(arr)
        while len(arr)>0:
            ans+=total
            if curr in d1:
                ch+=1
                added=True
                break
            else:
                total-=hq.heappop(arr)*(-1)
            curr+=1
        else:
            added=False
    else:
        added=False
        ch+=1
print(ans)




