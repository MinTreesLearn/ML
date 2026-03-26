import sys
import math
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
E or Two O

'''

def solve():
    t = II()
    for _ in range(t):
        n = II()
        a = LII()
        odds = []
        evens = []

        for i,num in enumerate(a):
            if num & 1:
                odds.append(i+1)
            else:
                evens.append(i+1)

            if evens or len(odds) > 1:
                break

        if evens:
            print(1)
            print(evens[0])
        elif len(odds) > 1:
            print(2)
            print(odds[0], odds[1])
        else:
            print(-1)

solve()