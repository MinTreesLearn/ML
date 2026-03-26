import math
from sys import stdin	
from collections import Counter, defaultdict, deque
from bisect import bisect_right
from typing import List, DefaultDict
 
 
def readarray(typ):
    return list(map(typ, stdin.readline().split()))
 
def readint():
    return int(input())
 
 
for _ in range(readint()):
    
    x = readint()

    print(1, x-1)

    