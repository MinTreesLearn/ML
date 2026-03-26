from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
 
M = mod = 10**9 + 7
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().split()]
def st():return input()
def val():return int(input())
def li2():return [i for i in input().split()]
def li3():return [int(i) for i in input()]

for _ in range(val()):
    n,m = li()
    c = li()
    l = [set() for i in range(n)]
    for i in range(m):
        a,b = li()
        l[b - 1].add(a)
    cnt = defaultdict(int)

    for i in range(n):
        if len(l[i]):
            cnt[hash(tuple(sorted(l[i])))] += c[i]
        
    gc = 0
    for i in cnt:
        gc = math.gcd(gc,cnt[i])
    print(gc)
    _ = st()