from statistics import median
import sys
from bisect import bisect_right, bisect_left
import os
import sys
from io import BytesIO, IOBase
from math import factorial, floor, inf, ceil, gcd
from collections import defaultdict, deque, Counter
from functools import cmp_to_key
from heapq import heappop, heappush, heapify

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

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(s)
def invr():
    return(map(int,input().split()))
def insr2():
    s = input()
    return(s.split(" "))

###functions

##better sqrt with binary search (since f**k float precision for large nums)

def sqrt(num):
    l, r  = 0, 10**18 + 7
    while r-l != 1:
        mid = (l+r)//2
        square = mid*mid
        if square <= num:
            l = mid
        else:
            r = mid
    return l

### Calculate C(n, r) mod p, where p is prime (fast with precalculation)

def build_mod_inverses(n, r, p):
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = i * fact[i - 1] % p
    
    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], p - 2, p)
    for i in range(n - 1, -1, -1):
        inv[i] = (i + 1) * inv[i + 1] % p
    
    return fact, inv

# fast C(n, r) mod p calculation using predefined fact and inv
def comb(n, r, p, fact, inv):
    return fact[n] * inv[r] % p * inv[n - r] % p if n >= r >= 0 else 0
 
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i and i != 1:
                divisors.append(n // i)
    return divisors

def dfs(graph, vertex):
    visited = set()
    tree = []
    deq = deque([vertex])
    while deq:
        vertex = deq.pop()
        if vertex not in visited:
            visited.add(vertex)
            deq.extend(graph[vertex])
            tree.append(vertex)
    return tree

def find_in_sorted_list(elem, sorted_list):
    # https://docs.python.org/3/library/bisect.html
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(sorted_list, elem)
    if i != len(sorted_list) and sorted_list[i] == elem:
        return i
    return -1

############ SEGMENT TREE ##############
class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a+b):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def __delitem__(self, idx):
        self[idx] = self._default
 
    def __getitem__(self, idx):
        return self.data[idx + self._size]
 
    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def __len__(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        start += self._size
        stop += self._size
 
        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res
 
    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
    
############ DSU ##############
class DisjointSetUnion():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n
    
    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
    
        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x
    
        self.parents[x] += self.parents[y]
        self.parents[y] = x
    
    def size(self, x):
        return -self.parents[self.find(x)]
    
    def same(self, x, y):
        return self.find(x) == self.find(y)
    
    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]
    
    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]
    
    def group_count(self):
        return self.group
    
    def all_group_members(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic
    
    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

###code

__ = inp()
for _ in range(__):
    def solve():
        
        n = inp()
        arr = inlt()
        mx = -inf
        nums = []
        for i in range(1, n):
            if arr[i-1] != -1 and arr[i] != -1:
                if abs(arr[i-1]-arr[i]) > mx:
                    mx = abs(arr[i-1]-arr[i])
                    mx_val = arr[i]
            elif arr[i-1] != -1:
                nums.append(arr[i-1])
            elif arr[i] != -1:
                nums.append(arr[i])
                
        if not nums:
            if max(arr) == -1:
                print(0, 0)
            else:
                print(0, max(arr))
            return

        med = floor((max(nums)+min(nums))//2)
        val = max(nums) - med
        if val < mx:
            print(mx, med)
        else:
            print(val, med)
        
        return
    solve()