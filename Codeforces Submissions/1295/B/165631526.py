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
    n, x = I()
    s = IS()
    z = s.count('0')
    d = 2 * z - n
    cnt = 0
    if d != 0:
        ans = set()
        if x % d == 0:
            z = x // d * n
            if z >= 0:
                ans.add(x // d * n)
        for i in range(n):
            el = s[i]
            if el == '0':
                cnt += 1
            else:
                cnt -= 1
            if (x - cnt) % d == 0:
                z = (x - cnt) // d * n + i + 1
                if z >= 0:
                    ans.add(z)
        print(len(ans))
    else:
        for i in range(n):
            if cnt == x:
                print(-1)
                return
            el = s[i]
            if el == '0':
                cnt += 1
            else:
                cnt -= 1
        print(0)





if __name__ == '__main__':
    for _ in range(II()):
        main()
    # main()