import math
from collections import Counter, deque, defaultdict
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import heapq
import itertools
import bisect


def S():
    return sys.stdin.readline().split()


def I():
    return [int(i) for i in sys.stdin.readline().split()]


def II():
    return int(sys.stdin.readline())


def IS():
    return sys.stdin.readline().replace('\n', '')


def main():
    q, x = I()
    s = [0] * (x + 1)
    a = 0
    for _ in range(q):
        el = II() % x
        s[el] += 1
        while s[a % x] > 0:
            s[a % x] -= 1
            a += 1
        print(a)


if __name__ == '__main__':
    # for _ in range(II()):
    #     main()
    main()