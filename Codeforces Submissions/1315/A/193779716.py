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
b > a
gcd(b,a) == 1

n = 1000
b => (2,n+1)
    a = n-b
        if gcd(a,b) == 1:
            cnt += 1
print(cnt)

6
1 5
2 4 x

x x x x x
x x x x x
x x x x x
x x x x x
x x x x x
x x x x x
x x x x x
x x x x x
x x ! x x
x x x x x
'''

# sys.stdin = open("backforth.in", "r")
# sys.stdout = open("backforth.out", "w")
input = sys.stdin.readline

directions = [[-1,-1],[-1,1],[1,-1],[1,1]]

def isCross(i,j,grid):
    for di, dj in directions:
        if grid[i+di][j+dj] != 'X':
            return False
    return True

def solve():
    t = II()
    for _ in range(t):
        a,b,x,y = MII()
        all_rows = max(b * x, b * (a - x - 1))
        all_cols = max(a * y, a * (b - y - 1))
        print(max(all_rows, all_cols))

solve() 