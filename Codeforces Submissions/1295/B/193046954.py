import sys, threading
import math
from os import path
from collections import deque, defaultdict, Counter
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
from random import randint
from heapq import *
from array import array
from types import GeneratorType
 
 
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
    n, x = readInts()
    s = readStr()
    mp = mydict(int)
    cur = 0
    for num in s:
        if num == '0':
            cur += 1
        else:
            cur -= 1

        mp[cur] += 1

    p = cur
    ans = 0
    if x == 0 and p == 0:
        print(-1)
        return

    # print(mp, p)
    if x == 0:
        ans += 1

    for num in mp.getkeys():

        dif = (x-num)
        # print('d', dif)
        if p != 0:
            if dif%p == 0 and dif//p >= 0:
                ans += mp[num]

        else:
            if x == num:
                print(-1)
                return

    print(ans)


def main():
    t = 1
    if path.exists("/Users/arijitbhaumik/Library/Application Support/Sublime Text/Packages/User/input.txt"):
        sys.stdin = open("/Users/arijitbhaumik/Library/Application Support/Sublime Text/Packages/User/input.txt", 'r')
        sys.stdout = open("/Users/arijitbhaumik/Library/Application Support/Sublime Text/Packages/User/output.txt", 'w')
    # sys.setrecursionlimit(100000) 
    t = readInts()
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()  