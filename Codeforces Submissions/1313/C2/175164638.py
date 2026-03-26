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

n = int(_input())
a = list(map(int, _input().split()))
f = [0] * n
for i in range(n):
    f[i] = i - 1
    while f[i] >= 0 and a[i] < a[f[i]]:
        f[i] = f[f[i]]
b = [n] * n
for i in range(n - 1, -1, -1):
    b[i] = i + 1
    while b[i] < n and a[i] < a[b[i]]:
        b[i] = b[b[i]]
c = [0] * (n + 1)
for i in range(n):
    c[i + 1] = c[f[i] + 1] + a[i] * (i - f[i])
d = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    d[i] = d[b[i]] + a[i] * (b[i] - i)
# print(*a)
# print(*f)
# print(*b)
# print(*c)
# print(*d)
u, v = 0, -1
for i in range(n):
    x = c[i] + d[i]
    if x > v:
        u, v = i, x
# print(u, v)
x = a[u]
for i in range(u - 1, -1, -1):
    x = min(x, a[i])
    a[i] = x
x = a[u]
for i in range(u + 1, n):
    x = min(x, a[i])
    a[i] = x
print(*a)