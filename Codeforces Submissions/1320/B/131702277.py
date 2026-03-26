import bisect
import collections
import copy
import enum
import functools
import heapq
import itertools
import math
import random
import re
import sys
import time
import string
from typing import List
sys.setrecursionlimit(3001)

input = sys.stdin.readline

ng= collections.defaultdict(list)
sp = collections.defaultdict(list)

n,m= map(int,input().split())
for _ in range(m):
    u,v = map(int,input().split())
    ng[v].append(u)
k = int(input())
ks = list(map(int,input().split()))

q = []
vis=[0]*(n+1)
q.append(ks[-1])
vis[ks[-1]]=1
while q:
    nxt = set()
    for cq in q:
        for nq in ng[cq]:
            if vis[nq]==0:
                sp[nq].append(cq)
                nxt.add(nq)
    q = list(nxt)
    for cq in q:
        vis[cq] = 1
mn = 0
mx=  0
for i in range(1,k):
    if ks[i] not in sp[ks[i-1]]:
        mn+=1
        mx+=1
    elif len(sp[ks[i-1]])>1:
        mx+=1
print(mn,mx)

            


