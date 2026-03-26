import sys, threading
import math
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
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
    return n%(1000000000 + 7)


def upper_bound(a, num):
     l = 0
     r = len(a)-1
     ans = -1
     while l <= r:
         mid = (l+r)//2
         if a[mid] > num:
             ans = mid
             r = mid-1
         else:
             l = mid+1
 
     return ans 


def solve(t):
    # print(f'Case #{t}: ', end = '')
    a = readStr()
    b = readStr()
    cnt = 1
    mpind = defaultdict(list)
    for i, c in enumerate(a):
        mpind[c].append(i)

    j = 0
    lind = -1
    for c in b:
        ui = upper_bound(mpind[c], lind)

        if ui == -1:
            lind = -1
            ui = upper_bound(mpind[c], lind)
            cnt += 1


        if ui == -1 and lind == -1:
            print(-1)
            return
        else:
            lind = mpind[c][ui]

    print(cnt)


def main():
    t = 1
    if path.exists("F:/Comp Programming/input.txt"):
        sys.stdin = open("F:/Comp Programming/input.txt", 'r')
        sys.stdout = open("F:/Comp Programming/output1.txt", 'w')
    # sys.setrecursionlimit(1e6) 
    t = readInts()
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()  