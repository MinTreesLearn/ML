from sys import stdin,stdout
input = stdin.readline
from math import gcd,ceil,sqrt,inf,factorial
# from collections import Counter
# from heapq import heapify,heappop,heappush
# from time import time
# from bisect import bisect, bisect_left


for _ in range(int(input())):
    n = int(input())
    p = int(n)
    fac = set()
    for i in range(2,int(sqrt(n)) + 2):
        count = 0
        while p%i == 0 :
            count += 1
            p = p//i
        if count >= 1:
            fac.add(i)
            if count>= 3:
                fac.add(i**2)
    t = []            
    for i in fac:
        t.append(i)            
    if len(t) >= 2:
        temp1 = t[0]
        temp2 = t[1]
        k = n//(temp1*temp2)
        fac = {temp1,temp2,k}
        if len(fac) == 3 and k != 1:  
            print("YES")
            print(*fac)
        else:
            print("NO")    
    else:
        print("NO")              