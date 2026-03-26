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


n = ip()
ax = lmip()
tx = lmip()
a = [[ax[i], tx[i]] for i in range(n)]
a.sort(key=lambda x: (x[0], x[1]))
pq = []
push(pq, -a[0][1])
s = a[0][1]
ans = 0
now = a[0][0]
# print(a)
for i in range(1, n):
    if a[i][0] == now:
        push(pq, -a[i][1])
        s += a[i][1]
        continue
    # print(pq)
    while len(pq) > 1 and now < a[i][0]:
        s -= -pop(pq)
        ans += s
        now += 1
    if now == a[i][0]:
        s += a[i][1]
        push(pq, -a[i][1])
    else:
        pq.clear()
        push(pq, -a[i][1])
        now = a[i][0]
        s = a[i][1]

while len(pq) > 1:
    s -= -pop(pq)
    ans += s
print(ans)


######## Praise greedev ########