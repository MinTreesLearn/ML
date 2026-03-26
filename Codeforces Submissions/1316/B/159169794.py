import os
import sys
from collections import Counter as ctr, deque as dq,defaultdict
from io import BytesIO, IOBase
from types import GeneratorType

from re import search

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
input = lambda: sys.stdin.readline().rstrip('\r\n')
 
from bisect import bisect_left as bl, insort_right
from bisect import bisect_right as br

inp = lambda: int(sys.stdin.readline().rstrip("\r\n"))
mi = lambda: map(int, sys.stdin.readline().rstrip("\r\n").split())
li = lambda: list(mi())
lb = lambda: list(map(int, sys.stdin.readline().rstrip("\r\n")))
ls = lambda: list(sys.stdin.readline().rstrip("\r\n"))
bi = lambda n: bin(n).replace("0b", "")
dd = lambda : defaultdict(lambda : [])
sbstr=lambda a,s: search('.*'.join(a),s)

yn = ['No', 'Yes']
YN = ['NO', 'YES']
YY = "YES"
NN = "NO"
yy = "Yes"
nn = "No"

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc

def isPrime(n):
    if n <= 1:
        return True
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i = i + 6
    return True

def nf(n,a):
    b=a*a
    c=b*a
    d=c*a
    e=n
    ct=0
    while e%a==0:
        if e%d==0:
            ct+=4
            e=e//d
        if e%c==0:
            ct+=3
            e=e//c
        if e%b==0:
            ct+=2
            e=e//b
        if e%a==0:
            ct+=1
            e=e//a
    return ct

import heapq as hq

class PQ:
    def __init__(self,a=[]):
        self.a=a.copy()
        hq.heapify(self.a)
    def pop(self):
        return hq.heappop(self.a)
    def push(self,x):
        hq.heappush(self.a,x)

'''
dp=[[-1]*r for i in range(n)]
mod=mod
def prod(n,r):
    if dp[n][r-1]==-1:
        if r>n+1:
            dp[n][r-1]=0
        elif n==0:
            dp[n][r-1]=a[0]
        elif r==0:
            dp[n][r-1]=1
        else:
            dp[n][r-1]=(a[n]*prod(n-1,r-1)+prod(n-1,r))%mod
    return dp[n][r-1]
'''

from math import gcd

def sbsq(a,s):
    i=0
    for x in s:
        if i>=len(a):
            break
        if x==a[i]:
            i+=1
    return i==len(a)

def main(kase):
    n=inp()
    s=input()
    r=s[::-1]
    ans=[]
    for i in range(n-1,-1,-1):
        sw=n-i
        if sw%2:
            ans.append((s[i:]+r[sw:],n-sw+1))
        else:
            ans.append((s[i:]+s[:i],n-sw+1))
    t=min(ans)
    print(t[0])
    print(t[1])


if __name__ == "__main__":
    test_Cases=1
    test_Cases=inp()
    for i in range(test_Cases):
        main(i)