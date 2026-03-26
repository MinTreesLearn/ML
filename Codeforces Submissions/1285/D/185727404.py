#!/usr/bin/env python3

import io, os, sys
from sys import stdin, stdout

# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def input(): return stdin.readline().strip()
def read_int_list(): return list(map(int, input().split()))
def read_int_tuple(): return tuple(map(int, input().split()))
def read_int(): return int(input())

from itertools import permutations, chain, combinations, product
from math import factorial, gcd
from collections import Counter, defaultdict, deque
from heapq import heappush, heappop, heapify
from bisect import bisect_left
from functools import lru_cache

### CODE HERE

def ans_slow(A):
    ret = max(A)
    for x in range(4*max(A)):
        ret = min(ret, max([a^x for a in A]))
    return ret

def any_set(d, A):
    mask = (1 << d)
    for a in A:
        if mask & a:
            return True
    return False

def lowest_d(A):
    for d in range(33, -1, -1):
        if any_set(d, A):
            return d
    assert(False)

def ans_list(A):
    if len(A) <= 1: return 0

    d = lowest_d(A)
    mask = (1 << d)

    L = []
    R = []

    for a in A:
        if mask & a:
            L += [a]
        else:
            R += [a]

    L = [l^mask for l in L]

    if len(L) == 0:
        return ans_list(R)
    if len(R) == 0:
        return ans_list(L)

    L = list(set(L))
    R = list(set(R))

    # print(A, "split into", L, R)

    assert(len(L) < len(A))
    assert(len(R) < len(A))
    
    return (1 << d) + min(ans_list(R), ans_list(L))

if False:
    for _ in range(10000):
        import random
        A = [random.randint(1, 15) for _ in range(15)]
        A = list(sorted(set(A)))
        if ans_slow(A) != ans_list(A):
            print(A, ans_slow(A), ans_list(A))
            assert(False)
else:
    input()
    A = read_int_list()
    A = list(set(A))
    print(ans_list(A))
    # A = [1, 2, 3, 5]
    # print(ans(A))