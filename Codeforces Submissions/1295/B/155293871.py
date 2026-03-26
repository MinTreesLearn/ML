import sys, math
import heapq

from dataclasses import dataclass
from collections import deque
from bisect import bisect_left, bisect_right

input = sys.stdin.readline

hqp = heapq.heappop
hqs = heapq.heappush


# input
def ip(): return int(input())
def sp(): return str(input().rstrip())


def mip(): return map(int, input().split())
def msp(): return map(str, input().split().rstrip())


def lmip(): return list(map(int, input().split()))
def lmsp(): return list(map(str, input().split()))


# gcd, lcm
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def lcm(x, y):
    return x * y // gcd(x, y)


# prime
def isPrime(x):
    if x <= 1: return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


# Union Find
# p = [i for i in range(272727)]

def find(x):
    if x == p[x]:
        return x
    p[x] = find(p[x])
    return p[x]


def union(x, y, s):
    x = find(x)
    y = find(y)

    if x != y:
        p[y] = x


def getPow(a, x):
    ret = 1
    while x:
        if x & 1:
            ret = (ret * a) % MOD
        a = (a * a) % MOD
        x >>= 1
    return ret


############ Main! #############

for ttt in range(ip()):
    n, x = mip()
    s = sp()

    p = [0 for _ in range(n + 1)]
    for i in range(n):
        if s[i] == '0':
            p[i] = p[i - 1] + 1
        else:
            p[i] = p[i - 1] - 1

    f = False
    ans = 0

    for i in range(n):
        if p[n - 1] == 0 and p[i - 1] == x:
            f = True
            break
        if p[n - 1] == 0:
            continue
        if (x - p[i - 1]) % p[n - 1] == 0 and (x - p[i - 1]) // p[n - 1] >= 0:
            ans += 1

    print(ans if not f else -1)


######## Priest greedev ########