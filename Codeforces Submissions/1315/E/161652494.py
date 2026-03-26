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

inf = -10 ** 18
chk = [False for _ in range(1 << 17)]
dp = [[0 for _ in range(4)] for _ in range(1 << 17)]
n, k = mip()
a = lmip()
for i in a:
    chk[i - 1] = True

for i in range(1, 1 << (n - 1)):
    for j in range(4):
        dp[i][j] = inf

for i in range(1 << (n - 1), 1 << n):
    dp[i][0] = 0
    if chk[(i - (1 << (n - 1))) * 2] or chk[(i - (1 << (n - 1))) * 2 + 1]:
        dp[i][1] = 1
        dp[i][2] = 1
    else:
        dp[i][1] = inf
        dp[i][2] = inf

    if chk[(i - (1 << (n - 1))) * 2] and chk[(i - (1 << (n - 1))) * 2 + 1]:
        dp[i][3] = 1
    else:
        dp[i][3] = inf

for i in range((1 << (n - 1)) - 1, 0, -1):
    for j in range(4):
        for k in range(4):
            dp[i][j | k] = max(dp[i][j | k], dp[i * 2][j] + dp[i * 2 + 1][k] + (j | k))

ans = dp[1][0]
ans = max(ans, max(dp[1][1:]) + 1)
print(ans)


######## Praise greedev ########