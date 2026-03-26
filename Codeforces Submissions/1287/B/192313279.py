# author: cholebhature lover
from collections import *
from bisect import *
from heapq import *
from math import *
import sys


def input():
    return sys.stdin.readline().rstrip('\r\n')


def f(a, b):
    if a == b:
        return a
    else:
        if a == "S" and b == "T":
            return "E"
        if a == "S" and b == "E":
            return "T"
        if a == "E" and b == "S":
            return "T"
        if a == "E" and b == "T":
            return "S"
        if a == "T" and b == "S":
            return "E"
        if a == "T" and b == "E":
            return "S"


n, m = map(int, input().split())
s = set()
l = []
for i in range(n):
    a = input()
    l.append(a)
    s.add(a)
ans = 0
for i in range(n):
    for j in range(i+1, n):
        ss = ""
        for k in range(m):
            ss += f(l[i][k], l[j][k])
        if ss in s:
            ans += 1
print(ans//3)
