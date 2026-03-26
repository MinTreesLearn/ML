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
    a, b, p = mip()
    s = sp()
    n = len(s)
    i = n - 2
    c = [0 for _ in range(n - 1)]
    x = 0
    while i >= 0:
        now = s[i]
        while i >= 0 and now == s[i]:
            if now == "A":
                c[i] = x + a
            else:
                c[i] = x + b
            i -= 1
        if now == "A":
            x += a
        else:
            x += b

    ans = 0
    while ans < n - 1:
        if c[ans] > p:
            ans += 1
        else:
            break
    print(ans + 1)


######## Praise greedev ########