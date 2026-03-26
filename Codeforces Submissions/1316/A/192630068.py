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
min(m, sum(a))

if m is inf
then we just subtract every other
student's score and add to ourself

'''
def solve():
    t = II()
    for _ in range(t):
        n, m = MII()
        a = LII()
        print(min(m, sum(a)))

solve()
