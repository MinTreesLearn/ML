import os
import sys
from io import BytesIO, IOBase
from collections import Counter, defaultdict
from sys import stdin, stdout
import io
import math
import heapq
import bisect
import collections
def ceil(a, b):
    return (a + b - 1) // b
inf = float('inf')
def get():
    return stdin.readline().rstrip()
mod = 10 ** 5 + 7
# for _ in range(int(get())):
# n=int(get())
# l=list(map(int,get().split()))
# = map(int,get().split())
#########################################################
q,x = map(int,get().split())
d=defaultdict(int)
y=0
for _ in range(q):
    n=int(get())
    d[n%x]+=1
    while d[y] > 0 or d[y%x]>1:
        if d[y]==0:
            d[y] += 1
            d[y % x] -= 1
        y += 1
    print(y)





























