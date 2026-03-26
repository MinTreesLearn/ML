import os
import heapq
import sys
import math
import operator
from collections import defaultdict
from io import BytesIO, IOBase


"""def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)"""

"""def pw(a,b):
    result=1
    while(b>0):
        if(b%2==1): result*=a
        a*=a
        b//=2
    return result"""

def inpt():
    return [int(k) for k in input().split()]

def main():
    n=int(input())
    d=defaultdict(set)
    for _ in range(n-1):
        a,b=map(int,input().split())
        d[a].add(b)
        d[b].add(a)
    leaf=set()
    for key in d.keys():
        if(len(d[key])==1):
            leaf.add(key)

    while(len(leaf)>1):
        u, v = -1, -1
        for i in leaf:
            if(u==-1):
                u=i
                continue
            if(v==-1):
                v=i
                break
        q='? '+str(u)+' '+str(v)
        print(q)
        sys.stdout.flush()
        lca=int(input())
        if(lca==u or lca==v):
            print('! '+ str(lca))
            sys.stdout.flush()
            exit()
        leaf.remove(u)
        leaf.remove(v)
        for i in d[u]:
            d[i].remove(u)
            if(len(d[i])<=1):
                leaf.add(i)
        for i in d[v]:
            d[i].remove(v)
            if (len(d[i]) <= 1):
                leaf.add(i)
        d.pop(u)
        d.pop(v)
        if(len(d[lca])<=1):
            leaf.add(lca)
    for i in leaf:
        print('! '+str(i))
        sys.stdout.flush()
        break


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

if __name__ == "__main__":
    main()
