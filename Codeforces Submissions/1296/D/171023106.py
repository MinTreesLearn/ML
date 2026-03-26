import sys, io, os
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
inp    =lambda: int(input())
strng  =lambda: input().strip()
jn     =lambda x,l: x.join(map(str,l))
strl   =lambda: list(input().strip())
mul    =lambda: map(int,input().strip().split())
mulf   =lambda: map(float,input().strip().split())
seq    =lambda: list(map(int,input().strip().split()))

ceil   =lambda x: int(x) if(x==int(x)) else int(x)+1
ceildiv=lambda x,d: x//d if(x%d==0) else x//d+1

flush  =lambda: stdout.flush()
stdstr =lambda: stdin.readline()
stdint =lambda: int(stdin.readline())
stdpr  =lambda x: stdout.write(str(x) + "\n")
printls = lambda l: print(*l, sep=" ")
mod=1000000007

"""
Paste solution below
"""
def solution(h,a,b,k):
    for i in range(len(h)):
        if h[i]%(a+b) != 0:
            h[i] = h[i]%(a+b)
        else:
            h[i] = a+b
    
    h.sort()

    points = 0
    for i in range(len(h)):
        if h[i] <= a:
            points += 1
        elif ceildiv(h[i], a) - 1 <= k:
            k = k - (ceildiv(h[i], a) - 1)
            points += 1
        else:
            return points
        """while h[i]:
            if h[i] <= a:
                points += 1
                break
            elif k:
                k -= 1
                h[i] -= a
            else:
                return points
        """
    return points
    

        
            

            
t = 1#inp()
for i in range(t):
    n,a,b,k = mul()
    h = seq()
    ans = solution(h,a,b,k)
    print(ans)