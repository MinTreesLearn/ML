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


############### Main! ###############

def d(x, y):
    return abs(a[x] - a[y]) + abs(b[x] - b[y])

maxT = 10**17

x0, y0, ax, ay, bx, by = mip()
xs, ys, t = mip()

a = [x0]
b = [y0]

while ax * a[-1] + bx <= maxT and ay * b[-1] + by <= maxT:
    a.append(ax * a[-1] + bx)
    b.append(ay * b[-1] + by)

ans = 0
for k in range(len(a)):
    for l in range(len(a)):
        for r in range(l, len(a)):
            f = abs(xs - a[k]) + abs(ys - b[k])
            if d(k, l) + d(l, r) + f <= t or d(k, r) + d(l, r) + f <= t:
                ans = max(ans, r - l + 1)

print(ans)


######## Priest W_NotFoundGD ########