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

'''
AXXXB
AXXXA
BXXXA
BXXXB

()

()() (())

()()()
(()())
()(())
(())()
((()))

7
3
007
4
1000
5
00000
3
103
4
2020
9
123456789
30
001678294039710047203946100020

1
2
3
4

lcm(a,b) = (a*b)/gcd(a,b)

lcm(1,b) = b/1
lcm(2,b) = 2b/gcd(2,b)
lcm(3,b) = 3b/gcd(3,b)

1
2 1
1 3 2
2 1 4 3 = 2 + 2 + 12 + 12 = 28
2 4 1 3 =

1 2 3 4 5
1 3 2 5 4 = 1 + 6 + 6 + 20 + 20 = 53

2 1 4 5 3 = 2 + 2 + 12 + 20 + 15
'''

t = II()
for _ in range(t):
  n = II()
  nums = LII()
  total = 0
  ans = 0

  for num in nums:
    if num == 0:
      total += 1
      ans += 1
    else:
      total += num

  print(ans + int(total==0))