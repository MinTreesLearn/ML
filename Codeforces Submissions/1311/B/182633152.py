#!/usr/bin/env python3

import math
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from bisect import bisect_left as bs

def test_case():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    p = set(map(lambda x: int(x)-1, input().split()))

    while True:
        #find inversion
        pos = -1
        for i in range(n-1):
            if a[i] > a[i+1]:
                pos = i
                break

        if pos == -1:
            break
        if pos in p:
            a[pos], a[pos+1] = a[pos+1], a[pos]
        else:
            print("NO")
            return
    print("YES")

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        test_case()

if __name__ == '__main__':
    main()
