#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=tf-8
#

"""
"""

from operator import itemgetter
from collections import Counter
from collections import deque

import sys
input = sys.stdin.readline

def solve(a):
    b = [-1]
    c = [1]
    for aa in a:
        b.append(aa)
        c.append(1)
        while b[-2]*c[-1] >= b[-1]*c[-2]:
            a1 = b.pop()
            i1 = c.pop()
            b[-1] = a1+b[-1]
            c[-1] = i1+c[-1]

    for i, aa in enumerate(b[1:]):
        cc = c[i+1]
        d = aa/cc
        ss = (str(d)+"\n")*cc
        sys.stdout.write(ss)

def main():
    n= int(input())
    a = list(map(int,input().split()))
    solve(a)


if __name__ == "__main__":
    main()