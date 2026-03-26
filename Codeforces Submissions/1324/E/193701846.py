import sys
from collections import *
input = sys.stdin.readline
from math import *
def mrd(): return [int(x) for x in input().split()]
def rd(): return int(input())
MAXN = 2 * 10**5 + 5
INF = 10**16 * 2
mod = 10**9 + 7
#----------------------------------------------------------------------------------#

def solve():
    n, h, l, r = mrd()
    a = mrd()
    
    f = [-INF] * h
    f[0] = 0
    for x in a:
        g = f[:]
        for i in range(h):
            f[i] = max(g[(i - x + 1) % h], g[(i - x) % h]) + (l <= i <= r)
    print(max(f))


if __name__ == "__main__":
    solve()