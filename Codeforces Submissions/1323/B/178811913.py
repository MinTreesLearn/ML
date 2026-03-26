import bisect
import collections
import heapq
import io
import math
import os
import sys

LO = 'abcdefghijklmnopqrstuvwxyz'
Mod = 1000000007

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# _input = lambda: io.BytesIO(os.read(0, os.fstat(0).st_size)).readline().decode()
_input = lambda: sys.stdin.buffer.readline().strip().decode()

# for _ in range(int(_input())):
for _ in range(1):
    n, m, k = map(int, _input().split())
    a = sorted(map(len, filter(None, _input().replace(' ', '').split('0'))))
    b = sorted(map(len, filter(None, _input().replace(' ', '').split('0'))))
    x = [0]
    if a:
        s = sum(a)
        i = 0
        for w in range(1, a[-1] + 1):
            x.append(s)
            s -= len(a) - i
            while i < len(a) and w >= a[i]:
                i += 1
    y = [0]
    if b:
        s = sum(b)
        i = 0
        for w in range(1, b[-1] + 1):
            y.append(s)
            s -= len(b) - i
            while i < len(b) and w >= b[i]:
                i += 1
    # print(a, b)
    # print(x, y)
    c = 0
    for u in range(1, len(x)):
        if k % u == 0:
            v = k // u
            if v < len(y):
                c += x[u] * y[v]
    print(c)
