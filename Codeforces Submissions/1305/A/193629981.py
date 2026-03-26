import sys
import math
import bisect
import heapq
import string
from collections import defaultdict,Counter,deque
 
def I():
    return input()
 
def II():
    return int(input())
 
def MII():
    return map(int, input().split())
 
def LI():
    return list(input().split())
 
def LII():
    return list(map(int, input().split()))
 
def GMI():
    return map(lambda x: int(x) - 1, input().split())
 
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))
 
def WRITE(out):
  return print('\n'.join(map(str, out)))
 
def WS(out):
  return print(' '.join(map(str, out)))
 
def WNS(out):
  return print(''.join(map(str, out)))

'''

1
1 2 | 2 1
1 2 3 | 

1 2 3 4 | 1 3 2 4
'''

# sys.stdin = open("backforth.in", "r")
# sys.stdout = open("backforth.out", "w")
input = sys.stdin.readline

def dist(c1, c2):
  return abs(c1[0] - c2[0]) + abs(c1[1] - c2[1])

def solve():
    t = II()
    for _ in range(t):
        n = II()
        a = sorted(LII())
        b = sorted(LII())
        WS(a)
        WS(b)

solve()