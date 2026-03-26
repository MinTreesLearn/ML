import sys, math
import heapq

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

def get(A, B, C, D):
    if (B[0] - A[0]) ** 2 + (B[1] - A[1]) ** 2 != (C[0] - D[0]) ** 2 + (C[1] - D[1]) ** 2:
        return False
    if (B[1] - A[1]) * (C[0] - D[0]) != (B[0] - A[0]) * (C[1] - D[1]):
        return False
    return True

n = ip()
a = []
for i in range(n):
    a.append(lmip())

can = True
for i in range(n // 2):
    if not get(a[i], a[i + 1], a[i + n // 2], a[(i + 1 + n // 2) % n]):
        can = False

print("YES" if can else "NO")

######## Praise greedev ########