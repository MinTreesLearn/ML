# watchu lookin at?

import sys
from math import *
# from itertools import *
# from heapq import heapify, heappop, heappush
# from bisect import bisect, bisect_left, bisect_right
from collections import deque, Counter, defaultdict as dd
mod = 10**9+7
abc = "abcdefghijklmnopqrstuvwxyz"
# Sangeeta Singh


def input(): return sys.stdin.readline().rstrip("\r\n")
def ri(): return int(input())
def rl(): return list(map(int, input().split()))
def rls(): return list(map(str, input().split()))
def isPowerOfTwo(x): return (x and (not(x & (x - 1))))
def lcm(x, y): return (x*y)//gcd(x, y)
def alpha(x): return ord(x)-ord('A')


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def d2b(n):
    s = bin(n).replace("0b", "")
    return (34-len(s))*'0'+s


def highestPowerof2(x):
    x |= x >> 1
    x |= x >> 2
    x |= x >> 4
    x |= x >> 8
    x |= x >> 16
    return x ^ (x >> 1)


def nextPowerOf2(N):
    if not (N & (N - 1)):
        return N
    return int("1" + (len(bin(N)) - 2) * "0", 2)


def isPrime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


def factors(n):
    i = 1
    ans = []
    while i <= sqrt(n):
        if (n % i == 0):
            if (n / i != i):
                ans.append(int(n/i))
            if i != 1:
                ans.append(i)
        i += 1
    return ans


Primes = [1] * 100001
primeNos = []


def SieveOfEratosthenes(n):
    p = 2
    while (p * p <= n):
        if (Primes[p]):
            for i in range(p * p, n+1, p):
                Primes[i] = 0
        p += 1
    for p in range(2, n+1):
        if Primes[p]:
            primeNos.append(p)

# SieveOfEratosthenes(100000)
# P = len(primeNos)
# print("P", P)


def ncr(n, r):
    ans = 1
    while(r):
        ans *= n
        ans %= mod
        n -= 1
        r -= 1
    return ans

############ Main! #############
# mod = 998244353


def skyScrapper(ind, a, n):
    ans = [0]*n
    ans[ind] = a[ind]
    for i in range(ind+1, n):
        ans[i] = min(ans[i-1], a[i])
    for i in range(ind-1, -1, -1):
        ans[i] = min(ans[i+1], a[i])
    return [sum(ans), ans]


def sangee():
    n = ri()
    a = rl()
    k = 0
    ans = []
    for i in range(n):
        ans.append(skyScrapper(i, a, n))
    m = max(ans)
    print(*m[1])
    # print(ans)


t = 1
for _ in range(t):
    sangee()
