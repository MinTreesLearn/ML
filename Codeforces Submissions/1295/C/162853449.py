import math
from collections import Counter, deque
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import heapq


def S():
    return sys.stdin.readline().split()


def I():
    return [int(i) for i in sys.stdin.readline().split()]


def II():
    return int(sys.stdin.readline())


def IS():
    return sys.stdin.readline().replace('\n', '')


def main():
    s = IS()
    n = len(s)
    t = IS()
    alphabet = set(s)
    if alphabet | set(t) != alphabet:
        print(-1)
        return
    suf_m = dict([(i, [-1] * n) for i in alphabet])
    suf_m[s[-1]][-1] = n - 1
    for i in range(n - 2, -1, -1):
        el = s[i]
        for a in alphabet:
            if a != el:
                suf_m[a][i] = suf_m[a][i + 1]
            else:
                suf_m[el][i] = i
    idx = -1
    op = 0
    for i in range(len(t)):
        el = t[i]
        idx = suf_m[el][idx + 1]
        if idx == n - 1:
            op += 1
            idx = -1
        elif idx == -1:
            op += 1
            idx = suf_m[el][0]
    if idx != -1:
        op += 1
    print(op)



if __name__ == '__main__':
    for _ in range(II()):
        main()
    # main()