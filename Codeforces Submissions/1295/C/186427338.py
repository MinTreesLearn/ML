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

for _ in range(int(get())):
    s=get()
    t=get()
    d=defaultdict(list)
    for i in range(len(s)):
        d[s[i]].append(i)
    y=-1
    ans=0
    for i in range(len(t)):
        l=d[t[i]]
        if len(l)==0:
            print(-1)
            break
        start=0
        end=len(l)-1
        tmp=y
        while start<=end:
            mid=(start+end)//2
            if l[mid]<=y:
                start=mid+1
            else:
                tmp=l[mid]
                end=mid-1
        # print(tmp,y)
        if y==-1:
            y=tmp
            ans+=1
        elif tmp<=y:
            ans+=1
            y=l[0]
        else:
            y=tmp
            continue
    else:
        print(ans)























