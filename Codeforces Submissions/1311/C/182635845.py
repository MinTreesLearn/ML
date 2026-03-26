#!/usr/bin/env python3

import math
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from bisect import bisect_left as bs

def test_case():
    n, m = map(int, input().split())
    s = input()
    p = list(map(int, input().split()))

    pref = [[0 for _ in range(26)] for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(26):
            pref[i][j] = pref[i-1][j]
        x = s[i-1]
        pref[i][ord(x)-ord('a')] += 1

    ans = [0 for _ in range(26)]
    for i in range(m):
        for j in range(26):
            ans[j] += pref[p[i]][j]
    for j in range(26):
        ans[j] += pref[n][j]
    print(*ans)

    


def main():
    t = 1
    t = int(input())
    for _ in range(t):
        test_case()

if __name__ == '__main__':
    main()
