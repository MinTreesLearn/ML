"""
    Author - Satwik Tiwari .
    20th Oct , 2020  - Tuesday
"""

#===============================================================================================
#importing some useful libraries.


from __future__ import division, print_function
from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase
from functools import cmp_to_key

# from itertools import *
from heapq import *
from math import gcd, factorial,floor,ceil

from copy import deepcopy
from collections import deque


from bisect import bisect_left as bl
from bisect import bisect_right as br
from bisect import bisect

#==============================================================================================
#fast I/O region
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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

# inp = lambda: sys.stdin.readline().rstrip("\r\n")

#===============================================================================================
### START ITERATE RECURSION ###
from types import GeneratorType
def iterative(f, stack=[]):
  def wrapped_func(*args, **kwargs):
    if stack: return f(*args, **kwargs)
    to = f(*args, **kwargs)
    while True:
      if type(to) is GeneratorType:
        stack.append(to)
        to = next(to)
        continue
      stack.pop()
      if not stack: break
      to = stack[-1].send(to)
    return to
  return wrapped_func
#### END ITERATE RECURSION ####

#===============================================================================================
#some shortcuts

def inp(): return sys.stdin.readline().rstrip("\r\n") #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
# def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  #as stdout.write always print sring.
def testcase(t):
    for pp in range(t):
        solve(pp)
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def google(p):
    print('Case #'+str(p)+': ',end='')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(x, y, p) :
    res = 1     # Initialize result
    x = x % p  # Update x if it is more , than or equal to p
    if (x == 0) :
        return 0
    while (y > 0) :
        if ((y & 1) == 1) : # If y is odd, multiply, x with result
            res = (res * x) % p

        y = y >> 1      # y = y/2
        x = (x * x) % p
    return res
def ncr(n,r): return factorial(n) // (factorial(r) * factorial(max(n - r, 1)))
def isPrime(n) :
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
    return True
inf = pow(10,20)
mod = 998244353
#===============================================================================================
# code here ;))

class FenwickTree:
    def __init__(self, x):
        """transform list into BIT"""
        self.bit = x
        for i in range(len(x)):
            j = i | (i + 1)
            if j < len(x):
                x[j] += x[i]

    def update(self, idx, x):
        """updates bit[idx] += x"""
        while idx < len(self.bit):
            self.bit[idx] += x
            idx |= idx + 1

    def query(self, end):
        """calc sum(bit[:end])"""
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x

    def findkth(self, k):
        """Find largest idx such that sum(bit[:idx]) <= k"""
        idx = -1
        for d in reversed(range(len(self.bit).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(self.bit) and k >= self.bit[right_idx]:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1

    def printpref(self):
        out = []
        for i in range(len(self.bit) + 1):
            out.append(self.query(i))
        print(out)

def solve(case):
    n,m = sep()
    a = lis()

    for i in range(m):
        a[i] -=1

    temp = [1 for i in range(n)]
    for i in range(m):
        temp.append(0)

    f = FenwickTree(temp)

    mn = [i for i in range(0,n)]
    for i in range(m):
        mn[a[i]] = 0

    mx = [i for i in range(n)]
    pos = [(n-i-1) for i in range(n)]

    for i in range(m):
        # f.printpref()
        # print(pos)
        # print(f.query(pos[a[i]]+1),a[i],pos[a[i]])
        mx[a[i]] = max(mx[a[i]],n - f.query(pos[a[i]] + 1))
        # print(mx,'===')
        f.update(pos[a[i]],-1)
        # f.printpref()
        pos[a[i]] = i+n
        f.update(pos[a[i]],1)
        # f.printpref()
        # print(pos)
        # print('=============')

    # print(mx)
    for i in range(n):
        mx[i] = max(mx[i],n - f.query(pos[i]+1))
    # print(mn)
    # print(mx)

    for i in range(n):
        print(mn[i]+1,mx[i]+1)



testcase(1)
# testcase(int(inp()))












