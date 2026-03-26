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

a = [[0 for _ in range(101010)] for _ in range(2)]
n, q = mip()

chk = 0
k = 0
for i in range(q):
    r, c = mip()
    r -= 1
    c -= 1
    if a[r][c] == 0:
        a[r][c] = 1
        k = 1
    else:
        a[r][c] = 0
        k = -1

    for j in range(-1, 2):
        if 0 <= c + j < n and a[r ^ 1][c + j] == 1:
            chk += k
    print("no" if chk else "yes")


######## Priest W_NotFoundGD ########