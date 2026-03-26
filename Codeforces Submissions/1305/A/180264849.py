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
    n = int(input())
    print(*sorted(map(int, input().split())))
    print(*sorted(map(int, input().split())))


def main():
    tests = int(input())
    for _ in range(tests):
        solve()


if __name__ == "__main__":
    main()
