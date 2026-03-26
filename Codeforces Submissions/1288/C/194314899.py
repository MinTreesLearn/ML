import sys
import math
import copy
import itertools
import bisect
from heapq import heappop, heappush, heapify

input = lambda: sys.stdin.readline().rstrip("\r\n")

def ilst():
    return list(map(int,input().split()))
    
def islst():
    return list(map(str,input().split()))
    
def inum():
    return map(int,input().split())
    
def freq(l):
    d = {}
    for i in l:
        d[i] = d.get(i,0)+1
    return d


n,m = inum()
print((math.factorial(n+2*m-1)//(math.factorial(2*m)*math.factorial(n-1)))%(10**9+7))
