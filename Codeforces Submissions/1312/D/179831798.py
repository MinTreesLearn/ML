import bisect
import collections
import heapq
import io
import math
import os
import random
import sys

LO = 'abcdefghijklmnopqrstuvwxyz'
# Mod = 1000000007
Mod = 998244353

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# _input = lambda: io.BytesIO(os.read(0, os.fstat(0).st_size)).readline().decode()
_input = lambda: sys.stdin.buffer.readline().strip().decode()

T = 1
# T = int(_input())
for _ in range(T):
    n, m = map(int, _input().split())
    if n > 2:
        p = 1
        for i in range(n, m + 1):
            p = p * i % Mod
        q = 1
        for i in range(1, m - (n - 1) + 1):
            q = q * i % Mod
        print(p * pow(q, Mod - 2, Mod) % Mod * pow(2, n - 3, Mod) * (n - 2) % Mod)
    else:
        print(0)