import abc
import itertools
import math
from math import gcd as gcd
import sys
import queue
import itertools
from heapq import heappop, heappush
import random
from array import array
from bisect import *

# input = lambda: sys.stdin.buffer.readline().decode().strip()
# inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
Mint, Mlong, out = 2 ** 31 - 1, 2 ** 63 - 1, []


# Solution starts here
def solve():
    n, x = map(int, input().split())
    s = str(input())

    b = {}
    curr = 0
    for i in s:
        if i == "0":
            curr += 1
        else:
            curr -= 1
        b[curr] = b[curr] + 1 if curr in b else 1

    if curr == 0:
        if x in b:
            print(-1)
        else:
            print(0)
        return

    dop = int(x == 0)

    db = curr
    mn, mx = min(list(b.keys())), max(list(b.keys()))

    if x < mn:
        if db >= 0:
            print(0 + dop)
            return
        x -= (mn - x + abs(db) - 1) // abs(db) * db
    elif x > mx:
        if db <= 0:
            print(0 + dop)
            return
        x -= (x - mx + abs(db) - 1) // abs(db) * db

    #print(mn, x, mx, db)
    res = 0
    while mn <= x <= mx:
        if x in b:
            res += b[x]
        x -= db

    print(res + dop)
    return


if __name__ == '__main__':
    multi_test = 1

    if multi_test == 1:
        t = int(sys.stdin.readline())
        for _ in range(t):
            solve()
    else:
        solve()
