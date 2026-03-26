import sys, math
import heapq

from collections import deque

input = sys.stdin.readline

hqp = heapq.heappop
hqs = heapq.heappush


# input
def ip(): return int(input())
def sp(): return str(input().rstrip())

def mip(): return map(int, input().split())
def msp(): return map(str, input().split().rstrip())

def lmip(): return list(map(int, input().split()))
def lmsp(): return list(map(str, input().split().rstrip()))


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
# p = [i for i in range(n + 1)]

def find(x):
    if x == p[x]:
        return x
    q = find(p[x])
    p[x] = q
    return q


def union(x, y):
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


def getInv(x):
    return getPow(x, MOD - 2)


############### Main! ###############

ans = [0, 0]

def f(x):
    global ans
    b = [-1 for _ in range(1 << m)] # index
    for i in range(n):
        bit = 0
        for j in range(m):
            bit |= (0 if a[i][j] < x else 1) << j  # not smaller than x: 1
        b[bit] = i

    for i in range(1 << m):
        for j in range(1 << m):
            if (i | j) == (1 << m) - 1 and b[i] != -1 and b[j] != -1:
                ans = [b[i] + 1, b[j] + 1]
                return True
    return False

n, m = mip()
a = []
for i in range(n):
    a.append(lmip())

lo = 0
hi = 10**9 + 234

while lo <= hi:
    mid = (lo + hi) // 2
    if f(mid):
        lo = mid + 1
    else:
        hi = mid - 1

print(*ans)

######## Priest W_NotFoundGD ########