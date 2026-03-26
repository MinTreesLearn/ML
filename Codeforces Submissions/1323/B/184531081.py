import os
import sys
from io import BytesIO, IOBase
from collections import Counter, defaultdict
from sys import stdin, stdout
import io
from math import *
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
#####################################################################
def divisors(n):
    i = 1
    l=set()
    while (i * i < n):
        if (n % i == 0):
            l.add(i)
        i += 1
    for i in range(int(sqrt(n)), 0, -1):
        if (n % i == 0):
            l.add(n//i)
    return l
#####################################################################
n,m,y = map(int,get().split())
l1=list(map(int,get().split()))
l2=list(map(int,get().split()))
l=divisors(y)
i=0
s1=defaultdict(int)
s2=defaultdict(int)
while i<n:
    x=0
    while i<n and l1[i]==1:
        x+=1
        i+=1
    i+=1
    s1[x]+=1
i=0
while i<m:
    x=0
    while i<m and l2[i]==1:
        x+=1
        i+=1
    i+=1
    s2[x] += 1
s3=[]
ans=0
# print(s1,s2)
for i in s1:
    for j in s2:
        for k in l:
            if y%k==0:
                if k<=i and y//k<=j:
                    ans+=(i-k+1)*(j-y//k+1)*s1[i]*s2[j]
print(ans)

