import sys, threading
import math
from os import path
from collections import deque, defaultdict, Counter
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
    def __init__(self, func=lambda: 0):
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
    return n%(1000000007) 


def solve(t):
    # print(f'Case #{t}: ', end = '')
    n, x, y = readInts()
    sm = x+y
    print(min(n, max(1, sm+1-n)), min(n, sm-1))


def main():
    t = 1
    if path.exists("F:/Comp Programming/input.txt"):
        sys.stdin = open("F:/Comp Programming/input.txt", 'r')
        sys.stdout = open("F:/Comp Programming/output1.txt", 'w')
    # sys.setrecursionlimit(100000) 
    t = readInts()
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()  