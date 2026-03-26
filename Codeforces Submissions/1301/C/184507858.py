import sys
from math import *
from collections import *
inp = lambda: sys.stdin.buffer.readline().decode().strip()
out=sys.stdout.write
# n=int(inp())
# arr=list(map(int,inp().split()))
for _ in range(int(inp())):
    n,m=map(int,inp().split())
    ones=m
    zeros=n-m
    buckets=ones+1
    total=(n*(n+1))//2
    h=ceil(zeros/buckets)
    l=max(0,h-1)
    #x.h+y.l=zeros
    #x+y=buckets
    y=buckets*h-zeros
    x=buckets-y
    remove=(x*h*(h+1))//2+(y*l*(l+1))//2
    print(total-remove)