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


'''
d = rt

'''
import sys
input = sys.stdin.readline
import math
from collections import defaultdict

t=II()
for _ in range(t):
  x,y,a,b=MII()
  d = y-x
  if d%(a+b)!=0:
    print(-1)
  else:
    print(d//(a+b))
