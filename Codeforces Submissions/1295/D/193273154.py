# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py
import os
import sys
import threading
from io import BytesIO, IOBase
import math
from heapq import heappop, heappush, heapify, heapreplace
from collections import defaultdict, deque, OrderedDict, Counter
from bisect import bisect_left, bisect_right
from functools import lru_cache
from itertools import combinations
#import re
mod = 1000000007
mod1 = 998244353
#sys.setrecursionlimit(10**8)
alpha = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}


def read():
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 

# ------------------------------------------- Algos --------------------------------------------------------
def primeFactors(n):
    #arr = []
    dic = defaultdict(int)
    l = 0
    while n % 2 == 0:
        #arr.append(2)
        dic[2] += 1
        l += 1
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            #arr.append(i)
            dic[i] += 1
            l += 1
            n = n // i
    if n > 2:
        dic[n] += 1
        #arr.append(n)
        l += 1
    #return arr
    return dic
    #return l
def primeFactorsSet(n):
    s = set()
    while n % 2 == 0:
        s.add(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            s.add(i)
            n = n // i
    if n > 2:
        s.add(n)
    return s
def divisors(n) :
    ans = []
    i = 1
    while i <= math.sqrt(n):
        if (n % i == 0) :
            ans.append(i)
            '''if n//i != i:
                ans.append(n//i)'''
        i += 1

    return ans
def sieve(n):
    res=[0 for i in range(n+1)]
    #prime=set([])
    prime=[]
    for i in range(2,n+1):
        if not res[i]:
            #prime.add(i)
            prime.append(i)
            for j in range(1,n//i+1):
                res[i*j]=1
    return prime
def isPrime(n) : # Check Prime Number or not 
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
def countPrimesLessThanN(n):
    seen, ans = [0] * n, 0
    for num in range(2, n):
        if seen[num]: continue
        ans += 1
        seen[num*num:n:num] = [1] * ((n - 1) // num - num + 1)
    return ans
def gcd(x, y):
    return math.gcd(x, y)
def lcm(a,b):
    return (a // gcd(a,b))* b
def isBitSet(n,k):
    # returns the count of numbers up to N having K-th bit set.
    res = (n >> (k + 1)) << k
    if ((n >> k) & 1):
        res += n & ((1 << k) - 1)
    return res
def popcount(x):
    x = x - ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    return x & 0x0000007f
def modular_exponentiation(x, y, p):    #returns (x^y)%p
    res = 1
    x = x % p
    if (x == 0) :
        return 0
    while (y > 0) :
        if ((y & 1) == 1) :
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def modInverse(A, M):  # returns (1/A) % M
    g = gcd(A, M)
    if (g == 1):
        return modular_exponentiation(A, M - 2, M)

def nCr(n, r, p):    # returns nCr % p
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
            p - 2, p)) % p
def smallestDivisor(n):
    if (n % 2 == 0):
        return 2
    i = 3
    while(i * i <= n):
        if (n % i == 0):
            return i
        i += 2
    return n
def numOfDivisors(n):
    def pf(n):
        dic = defaultdict(int)
        while n % 2 == 0:
            dic[2] += 1
            n = n // 2
        for i in range(3,int(math.sqrt(n))+1,2):
            while n % i== 0:
                dic[i] += 1
                n = n // i
        if n > 2:
            dic[n] += 1
        return dic
    p = pf(n)
    ans = 1
    for item in p:
        ans *= (p[item] + 1)
    return ans
def SPF(spf, MAXN):
    spf[1] = 1
    for i in range(2, MAXN):
        spf[i] = i
    for i in range(4, MAXN, 2):
        spf[i] = 2
    for i in range(3, math.ceil(math.sqrt(MAXN))):
        if (spf[i] == i):
            for j in range(i * i, MAXN, i):
                if (spf[j] == j):
                    spf[j] = i

# A O(log n) function returning prime
# factorization by dividing by smallest
# prime factor at every step
def factorizationInLogN(x, spf):
    #ret = list()
    #dic = defaultdict(int)
    set_ = set()
    while (x != 1):
        #ret.append(spf[x])
        #dic[spf[x]] += 1
        set_.add(spf[x])
        x = x // spf[x]
    #return ret
    #return dic
    return set_

#MAXN = 100001
#spf = [0 for i in range(MAXN)]

#SPF(spf, MAXN)

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self.size[b]
        return True

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets
#a = sorted(range(n), key=arr.__getitem__)
'''def interact(a, b):
    print(f"? {a} {b}", flush = True)
    return int(input())'''
# -------------------------------------------------- code -------------------------------------------------

def lis():
    return [int(i) for i in input().split()]

def main():

    t = int(input())
    for _ in range(t):
        a,m = map(int, input().split())

        g = gcd(a, m)

        m1 = m//g

        res = m1
        i = 2
        while i*i <= m1:
            if m1%i == 0:
                while m1%i == 0:
                    m1 //= i

                res -= res//i
            i += 1

        if m1 > 1:
            res -= res//m1


        print(res)

 
# ---------------------------------------------- region fastio ---------------------------------------------
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

# -------------------------------------------------- end region ---------------------------------------------
# uncomment the below code if your code is using recursion and submit in python 3 instead of pypy
# and comment the whole if statement"
'''threading.stack_size(10**8)
t = threading.Thread(target=main)
t.start()
t.join()'''
if __name__ == "__main__":
    #read()
    main()