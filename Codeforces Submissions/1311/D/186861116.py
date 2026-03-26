from heapq import heappop, heappush, heapify
from math import ceil, factorial, gcd, log, floor
from sys import  stdin, stdout
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right, insort_right

inf = int(1e19)
input = stdin.readline
mod = 998244353
     
#D V ARAVIND
    
for _ in range (int(input())):
    a, b, c = map(int, input().split())
    ans = inf
    val = [1, 1, 1]
    for x in range (1, (2*a)+1):
        y = x
        while y <= (2*b):
            zm = (c//y)*y
            z = zm + y
            sol = min(c-zm, z-c) + abs(y-b) + abs(x-a)
            if sol < ans:
                ans = sol
                val[0] = x
                val[1] = y
                if c-zm <= z-c :
                    val[2] = zm
                else:
                    val[2] = z
            y += x
    print(ans)
    print(*val)