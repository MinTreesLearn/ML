from sys import stdin,stdout
input = stdin.readline
# from math import inf
# from collections import Counter
# from heapq import heapify,heappop,heappush
# from time import time
# from bisect import bisect, bisect_left


n,m = map(int,input().split())

ans = 1   
if n > 1000:
    print(0)
else:
    a = list(map(int,input().split()))
    for i in range(n):
        for j in range(i + 1,n):
            ans *= abs(a[i]-a[j])%m
            ans = ans%m 
    print(ans)               
         
