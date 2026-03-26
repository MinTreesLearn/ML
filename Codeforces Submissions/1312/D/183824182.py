import os
import sys
from io import BytesIO, IOBase
from collections import Counter, defaultdict
from sys import stdin, stdout
import io
import math
import heapq
import bisect
import collections
def ceil(a, b):
    return (a + b - 1) // b
inf = float('inf')
def get():
    return stdin.readline().rstrip()
def modfac(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv
    return factorials, invs
def modnCr(n,r):
    return fac[n] * inv[n-r] * inv[r] % mod
mod = 998244353
fac,inv = modfac(500000,mod)

def modFact(n, p):
    if n >= p:
        return 0

    result = 1
    for i in range(1, n + 1):
        result = (result * i) % p

    return result
def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1  # y = y/2
        x = (x * x) % p
    return res
# for _ in range(int(get())):
# n=int(get())
# l=list(map(int,get().split()))
# = map(int,get().split())
n,m= map(int,get().split())
print(((modnCr(m,n-1)%mod)*((n-2)%mod)*(power(2,n-3,mod)%mod))%mod)







