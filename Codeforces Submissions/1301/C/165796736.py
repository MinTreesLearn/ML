import math
import random
from collections import Counter, deque
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import heapq
from copy import deepcopy


def S():
    return sys.stdin.readline().split()


def I():
    return [int(i) for i in sys.stdin.readline().split()]


def II():
    return int(sys.stdin.readline())


def IS():
    return sys.stdin.readline().replace('\n', '')


def main():
    n, m = I()
    total = (n + 1) * n // 2
    g = n - m
    group = g // (m + 1)
    o = g % (m + 1)
    big_groups = o
    small_groups = m + 1 - o
    print(total - (group + 1) * group // 2 * small_groups - (group + 2) * (group + 1) // 2 * big_groups)



if __name__ == '__main__':
    for _ in range(II()):
        main()
    # main()