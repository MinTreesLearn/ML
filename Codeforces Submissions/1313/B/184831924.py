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
T = int(_input())
for _ in range(T):
    n, x, y = map(int, _input().split())
    print(max(1, min(n, x + y - n + 1)), min(n, x + y - 1))