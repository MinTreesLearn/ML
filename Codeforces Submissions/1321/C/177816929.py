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

for _ in range(1):
    n = int(_input())
    a = list(map(ord, _input()))
    b = [[] for _ in range(128)]
    for i, x in enumerate(a):
        b[x].append(i)
    l = list(range(-1, n - 1))
    r = list(range(1, n + 1))
    c = 0
    for x in range(ord('z') - 1, ord('a') - 1, -1):
        for i in b[x]:
            i1 = l[i]
            while i1 >= 0 and a[i1] == a[i] + 1:
                l[i] = i1 = l[i1]
                if l[i] >= 0:
                    r[l[i]] = i
                c += 1
            i2 = r[i]
            while i2 < n and a[i2] == a[i] + 1:
                r[i] = i2 = r[i2]
                if r[i] < n:
                    l[r[i]] = i
                c += 1

    print(c)