from math import ceil,gcd, log1p,sqrt,log2
from collections import Counter
#for ttt in range(int(input())):
n=int(input())
a=list(map(int,input().split()))
a.insert(0,0)
res=[0]*(n+1)
for i in range(n+1):
    res[i]=a[i]-i
dit={}
for i in range(n+1):
    if res[i] not in dit:
        dit[res[i]]=[a[i]]
    else:
        dit[res[i]].append(a[i])
summ=0 
for i,j in dit.items():
    summ=max(summ,sum(j))
print(summ)