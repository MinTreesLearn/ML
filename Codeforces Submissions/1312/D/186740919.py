import sys, threading
import math
from os import path
from collections import deque, Counter, defaultdict
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
from random import randint
import heapq
 
 
def readInts():
    x = list(map(int, (sys.stdin.readline().rstrip().split())))
    return x[0] if len(x) == 1 else x
 
 
def readList(type=int):
    x = sys.stdin.readline()
    x = list(map(type, x.rstrip('\n\r').split()))
    return x
 
 
def readStr():
    x = sys.stdin.readline().rstrip('\r\n')
    return x
 
 
write = sys.stdout.write
read = sys.stdin.readline
 
 
MAXN = 1123456


class mydict:
    def __init__(self, func):
        self.random = randint(0, 1 << 32)
        self.default = func
        self.dict = {}
 
    def __getitem__(self, key):
        mykey = self.random ^ key
        if mykey not in self.dict:
            self.dict[mykey] = self.default()
        return self.dict[mykey]
 
    def get(self, key, default):
        mykey = self.random ^ key
        if mykey not in self.dict:
            return default
        return self.dict[mykey]
 
    def __setitem__(self, key, item):
        mykey = self.random ^ key
        self.dict[mykey] = item
 
    def getkeys(self):
        return [self.random ^ i for i in self.dict]
 
    def __str__(self):
        return f'{[(self.random ^ i, self.dict[i]) for i in self.dict]}'

 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
def mod(n):
    return n%(998244353)


def power(bas, exp):
    if (exp == 0):
        return 1
    if (exp == 1):
        return bas
     
     
    if (exp % 2 == 0):
        t = power(bas, exp // 2)
        t = mod(t * t)
        return t    

    else:
        return mod(power(bas, exp-1)*bas)


def inverse(n):
    return power(n, 998244351)


global fact
def nCr(n, r):

    fac1 = mod(fact[n])
    fac2 = inverse(fact[r])
    fac3 = inverse(fact[n-r])
    return mod(fac1*fac2*fac3)


def solve(t):
    # print(f'Case #{t}: ', end = '')
    n, m = readInts()
    global fact
    fact = [1]
    fac = 1
    for i in range(1, m+1):
        fac = mod(mod(i)*mod(fac))
        fact.append(fac)

    print(mod(nCr(m, n-1)*power(2, max(0, n-3))*(n-2)))
        


def main():
    t = 1
    if path.exists("F:/Comp Programming/input.txt"):
        sys.stdin = open("F:/Comp Programming/input.txt", 'r')
        sys.stdout = open("F:/Comp Programming/output1.txt", 'w')
    # sys.setrecursionlimit(10**5) 
    # t = readInts()
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()  