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
def solution(s):
    def coordToString(coord):
        return str(coord[0]) + "," + str(coord[1])

    locations = {}
    shortest = [-1, -1]
    shortest_l = float('inf')
    curr_coord = [0, 0]
    locations[coordToString(curr_coord)] = -1
    for i in range(len(s)):
        ch = s[i]
        if ch == 'L':
            curr_coord[0] -= 1
        elif ch == 'R':
            curr_coord[0] += 1
        elif ch == 'U':
            curr_coord[1] += 1
        else:
            curr_coord[1] -= 1
        coord_string = coordToString(curr_coord)
        if coord_string in locations:
            if i - locations[coord_string] < shortest_l:
                shortest_l = i - locations[coord_string]
                shortest = [locations[coord_string]+2, i+1]
        locations[coord_string] = i
    return shortest if shortest[0] != -1 else [-1]


    

t = inp()
for i in range(t):
    n = inp()
    s = strng()
    ans = solution(s)
    print(*ans)