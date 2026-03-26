import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import gcd,log
MOD = int(1e9 + 7)
INF = int(1e20)
input = lambda :sys.stdin.readline().rstrip()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

t=int(input())

for _ in range(t):
    n=int(input())
    arr=li()
    odd=[];even=[]
    for i,a in enumerate(arr):
        if a%2==0:
            even.append(i+1)
            break
        else:
            odd.append(i+1)
            if len(odd)>1:
                break
    if len(even)>0:
        print(1)
        print(even[0])
    elif len(odd)>1:
        print(2)
        print("{} {}".format(odd[0],odd[1]))
    else:
        print(-1)
