from sys import stdin,stdout
input = stdin.readline
from math import inf
# from collections import Counter
# from heapq import heapify,heappop,heappush
 
 
for _ in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    d=0
    for k in range(99):
        for j in range(n):
            if (j+1) in b and a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
        a1  = sorted(a)        
        if a == a1:
            print("YES")
            d=1
            break
    if(d==0):
        print("NO")