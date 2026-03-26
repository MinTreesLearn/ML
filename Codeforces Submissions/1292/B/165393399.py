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

def check(p1, p2):
    p=tm(p1[0], p1[1], p2[0], p2[1])
    return (min(tm(p1[0], p1[1], xs, ys), tm(p2[0], p2[1], xs, ys))+p)<=t


def tm(x1, y1, x2, y2):
    return (abs(x2-x1) + abs(y2-y1))



x0 , y0, ax, ay, bx, by=map(int, input().split())
xs , ys, t=map(int, input().split())
xp=x0
yp=y0
# print(x0, y0)
# for i in range(40):
#     xp=(xp*ax) + bx
#     yp=(yp*ay) + by
#     print(xp, yp)

l=1
xc, yc=x0, y0
prev=float("inf")
flag=False
while True:
    k=tm(xc, yc, xs, ys)
    if k<prev:
        if k<=t:
            break
        else:
            l+=1
            xc=(xc*ax) + bx
            yc=(yc*ay) + by
            prev=k
    else:
        flag=True
        break
if flag:
    print(0)
else:
    r=l
    while tm(xc, yc, xs, ys)<=t:
        r+=1
        xc=(xc*ax) + bx
        yc=(yc*ay) + by
    # print(l, r)
    xc=x0
    yc=y0

    points=[[x0, y0]]
    for i in range(1, r+1):
        x0=(x0*ax) + bx
        y0=(y0*ay) + by
        points.append([x0, y0])
    # print(points)
    ans=[0, 0]
    for i in range(r+1):
        for j in range(i+1, r+1):
            # print(i, j)
            if check(points[i], points[j]) and (j-i+1)>(ans[1]-ans[0]+1):
                # print(i, j)
                ans=[i, j]
    print(ans[1]-ans[0]+1)


