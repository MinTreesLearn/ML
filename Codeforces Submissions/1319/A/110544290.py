import math
from collections import deque
from sys import stdin, stdout, setrecursionlimit
from string import ascii_letters
from decimal import *
letters = ascii_letters[:26]
from collections import defaultdict
#from functools import reduce
#input = stdin.readline
#print = stdout.write


def ceildiv(a, b):
    return a // b + (1 if a % b else 0)


n = int(input())
first = list(map(int, input().split()))
second = list(map(int, input().split()))
if first == second:
    print(-1)
    exit(0)
cost = [1] * n
cnt = len([i for i in range(n) if first[i] == 1 and second[i] == 0])
left = first.count(1)
right = second.count(1)

delta = right - left
if delta < 0:
    print(1)
    exit(0)
if cnt == 0:
    print(-1)
    exit(0)

delta += 1
print(1 + ceildiv(delta, cnt))