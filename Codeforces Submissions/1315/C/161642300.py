import sys, math
import heapq

from collections import deque
from bisect import bisect_left, bisect_right

input = sys.stdin.readline

pop = heapq.heappop
push = heapq.heappush


# input
def ip(): return int(input())
def sp(): return str(input().rstrip())


def mip(): return map(int, input().split())
def msp(): return map(str, input().split())


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


def getPow(a, x):
    ret = 1
    while x:
        if x & 1:
            ret = (ret * a) % mod
        a = (a * a) % mod
        x >>= 1
    return ret


############ Main! #############

for tc in range(ip()):
    n = ip()
    b = lmip()
    a = [0 for _ in range(n * 2)]
    c = [False for _ in range(n * 2 + 1)]
    for i in range(n):
        a[i * 2] = b[i]
        c[b[i]] = True
    fl = True
    for i in range(1, n * 2, 2):
        found = False
        for j in range(a[i - 1], n * 2 + 1):
            if not c[j]:
                a[i] = j
                c[j] = True
                found = True
                break
        if not found:
            fl = False
            break

    if fl:
        print(*a)
    else:
        print(-1)

######## Praise greedev ########