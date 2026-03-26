import gc
import heapq
import itertools
import math
import sqlite3
from collections import Counter, deque, defaultdict
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import threading
from heapq import *


def S():
    return sys.stdin.readline().split()


def I():
    return [int(i) for i in sys.stdin.readline().split()]


def II():
    return int(sys.stdin.readline())


def IS():
    return sys.stdin.readline().replace('\n', '')


def main():
    n, m, k = I()
    m -= 1
    k = min(m, k)
    m -= k
    fix = [float('inf')] * (k + 1)
    a = I()
    for i in range(m + 1):
        for j in range(k + 1):
            fix[j] = min(fix[j], max(a[i + j], a[-(m - i + (k - j)) - 1]))
    print(max(fix))





if __name__ == '__main__':
    for _ in range(II()):
        main()
    # main()