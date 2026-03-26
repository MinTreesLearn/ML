import sys
import math
import heapq
from collections import defaultdict,Counter,deque
 
input = sys.stdin.readline
 
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
WNS(s[(y-1)%n] + t[(y-1)%m])

'''

def solve():
    n,m = MII()
    s = I().split()
    t = I().split()
    q = II()
    for _ in range(q):
        y = II()
        WNS(s[(y-1)%n] + t[(y-1)%m])
    

solve()