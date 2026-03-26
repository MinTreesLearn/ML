import itertools
import math
import threading
import time
from builtins import input, range
from math import gcd as gcd
import sys
from io import BytesIO, IOBase
import queue
import itertools
import collections
from heapq import heappop, heappush
import random
import os
from random import randint
import decimal
from math import factorial as fac


def solve():
    n = int(input())
    b = list(map(int,input().split()))

    a = [0 for i in range(2* n)]
    can_use = {i+1 for i in range(2*n)}

    for i in range(n):
        a[2*i] = b[i]
        can_use.discard(b[i])

    can_use = list(can_use)
    if len(can_use) != n:
        print(-1)
        return

    can_use = set(can_use)
    for i in range(n):
        k = a[2*i]
        mn = 1<<60
        for j in can_use:
            if j > k and j < mn:
                mn = j
        if mn == 1<<60:
            print(-1)
            return
        a[2*i + 1] = mn
        can_use.discard(mn)

    print(*a)




if __name__ == '__main__':
    multytest = True

    if multytest:
        t = int(input())
        for i in range(t):
            solve()
    else:
        solve()
