import heapq
import math
import os
from collections import Counter, deque, defaultdict
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import threading
from heapq import *
import random


def S():
    return sys.stdin.readline().split()


def I():
    return [int(i) for i in sys.stdin.readline().split()]


def II():
    return int(sys.stdin.readline())


def IS():
    return sys.stdin.readline().replace('\n', '')


def main():
    n = II()
    s = IS()
    d = dict([(chr(i + 1), chr(i)) for i in range(ord('a'), ord('z'))])
    c = Counter(s)
    ans = 0
    while True:
        flag = False
        for i in range(ord('z'), ord('a'), -1):
            mx = chr(i)
            if flag:
                break
            if c[mx] > 0:
                for j in range(n):
                    if s[j] == mx:
                        if (j > 0 and s[j - 1] == d[mx]) or (j < n - 1 and s[j + 1] == d[mx]):
                            if 0 < j < n - 1:
                                s = s[:j] + s[j + 1:]
                            elif j == 0:
                                s = s[1:]
                            else:
                                s = s[:-1]
                            flag = True
                            ans += 1
                            n -= 1
                            break
        if not flag:
            break
    print(ans)



if __name__ == '__main__':
    # for _ in range(II()):
    #     main()
    main()