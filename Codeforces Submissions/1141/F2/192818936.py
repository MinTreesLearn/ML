import sys, os, io
input = lambda: sys.stdin.readline().rstrip('\r\n')
from collections import defaultdict
n = int(input())
a = list(map(int,input().split()))
has = defaultdict(list)
for j in range(n):
    lin = 0
    for i in range(j,-1,-1):
        lin += a[i]
        if lin in has and has[lin][-1]%n >= i:continue
        has[lin].append(i*n+j)
mx = max(has.values(),key=lambda x:len(x))
print(len(mx))
for i in mx:
    print(i//n+1,i%n+1)