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
 
def WNS(out):
  return print(' '.join(map(str, out)))
 
def WNS(out):
  return print(''.join(map(str, out)))

'''
AB
AABB
ABAB

BBAA X
AABBA

010101

x+y = n
x = n - y
x*y vs (n-y)^2

0  = 1
1  = 1
01 = max(1*1) = 1
10 = 1
00 = 4
11 = 4
11110 = 16

compare biggest group of 1's 0's and num1's * num0's

5 -1 -2
'''

# sys.stdin = open("backforth.in", "r")
# sys.stdout = open("backforth.out", "w")
input = sys.stdin.readline

def dist(c1, c2):
  return abs(c1[0] - c2[0]) + abs(c1[1] - c2[1])

def solve():
  t = II()
  for _ in range(t):
    n, d = MII()
    a = LII()

    added = 0
    for i in range(1,n):
      days_for_pile = i * a[i]
      if d >= days_for_pile:
        # Move all
        added += a[i]
        d -= days_for_pile
      else:
        # We can only move some and we're done
        moved = d//i
        added += moved
        break
    print(a[0] + added)


solve()