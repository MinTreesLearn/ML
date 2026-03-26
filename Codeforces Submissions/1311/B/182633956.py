#!/usr/bin/env python3

import math
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from bisect import bisect_left as bs

def test_case():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    p = sorted(list(map(lambda x: int(x)-1, input().split())))

    i = 0
    while i < m:
        j = i+1
        while j < m and p[j] == p[j-1]+1:
            j += 1
        x = p[i]
        y = p[j-1]+1
        a = a[:x] + sorted(a[x:y+1]) + a[y+1:]
        i = j
    done = True
    for i in range(n-1):
        if a[i] > a[i+1]:
            done = False
            break
    print("YES" if done else "NO")

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        test_case()

if __name__ == '__main__':
    main()
