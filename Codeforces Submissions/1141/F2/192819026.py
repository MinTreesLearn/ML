import sys, os, io
input = lambda: sys.stdin.readline().rstrip('\r\n')
from collections import defaultdict
n = int(input())
a = list(map(int,input().split()))
has = defaultdict(list)
def f(a,b):return a*n+b
def ff(a):return (a//n,a%n)
for j in range(n):
    lin = 0
    for i in range(j,-1,-1):
        lin += a[i]
        if lin in has and ff(has[lin][-1])[1] >= i:continue
        has[lin].append(f(i,j))
mx = max(has.values(),key=lambda x:len(x))
print(len(mx))
for i in mx:
    a,b = ff(i)
    print(a+1,b+1)