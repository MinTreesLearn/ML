
import math
import copy
import itertools
import bisect
import sys
from heapq import heapify, heappop, heappush

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
    
def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
    
def issub(s1,s2):   #s2 is a sub of s1
    j = 0
    for i in range(len(s1)):
        if s1[i] == s2[j]:
            j += 1
        if j == len(s2):
            return True
    return False

    
t = int(input())

for _ in range(t):
    n,m = inum()

    l = []

    for i in range(n):
        l.append(ilst())

    l.sort()

    low,high = m,m 
    prev = 0
    f = False 

    for i in range(n):
        high = min(high+l[i][0]-prev,l[i][2])
        low = max(low-(l[i][0]-prev),l[i][1])

        if high < l[i][1] or low > l[i][2]:
            f = True 
            break 
        prev = l[i][0]


    if not f:
        print("YES")
    else:
        print("NO")