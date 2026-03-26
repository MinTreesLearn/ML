import math
import sys
import queue
import itertools
from heapq import heappop, heappush
import random


def solve():
    def n(s):
        return ord(s) - 97

    s = str(input())
    q = int(input())

    d = [[0 for i in range(len(s) + 1)] for j in range(26)]
    d[n(s[0])][1] = 1

    for i in range(1, len(s)):
        for j in range(26):
            d[j][i + 1] = d[j][i]
        d[n(s[i])][i + 1] += 1

    for _ in range(q):
        l, r = map(int, input().split())
        if r - l == 0 or s[l - 1] != s[r - 1]:
            print("Yes")
        else:
            diff = 0
            for i in range(26):
                f = d[i][r] - d[i][l - 1]
                if f != 0:
                    diff += 1

            if diff >= 3:
                print("Yes")
            else:
                print("No")


if __name__ == '__main__':
    multi_test = 0

    if multi_test:
        t = int(sys.stdin.readline())
        for _ in range(t):
            solve()
    else:
        solve()
