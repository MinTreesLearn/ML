import sys
# from math import *
from heapq import *
from bisect import *
from itertools import *
from functools import *
from collections import *

def read(fn=int):
	return map(fn, input().split())

n,m = read()
mod = 998244353

v = 1
for i in range(m,m-n+1,-1):
    v = (v * i) % mod
for i in range(1,n):
    v = (v * pow(i,-1,mod)) % mod
v = (v * (n-2)) % mod
v = (v * pow(2,n-3,mod)) % mod
print(v)