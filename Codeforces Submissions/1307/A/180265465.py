from collections import *
from heapq import *
from bisect import *
from itertools import *
from functools import *
from math import *
from string import *
import operator
import sys

input = sys.stdin.readline


def solve():
    n, d = map(int, input().split())
    A = list(map(int, input().split()))
    cost = lambda i: i
    ans = A[0]

    for i in range(1, n):
        moved = min(d // cost(i), A[i])
        ans += moved
        d -= moved * cost(i)

    print(ans)

def main():
    tests = int(input())
    for _ in range(tests):
        solve()


if __name__ == "__main__":
    main()
