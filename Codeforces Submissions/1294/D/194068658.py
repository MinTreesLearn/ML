from sys import stdin,stdout
input = stdin.readline
from math import sqrt,gcd
# from collections import Counter
# from heapq import heapify,heappop,heappush
# from time import time
# from bisect import bisect, bisect_left
				

#! Checking remainder with x if number of remainder is greater then given count then count += 1

n,x = map(int,input().split())
rem = [0 for i in range(x)]
count  = 0
for i in range(n):
    p = int(input())
    op = p%x
    rem[op] += 1
    while rem[count%x] > count//x:
        count += 1    
    print(count)

	