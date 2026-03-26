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

< 10 = x
10 = 11
12 = 12
...
18 = 19
19 = 21
...
100 // 10 = 10 cashback
spent 100, 10 cashback = 1 -> 111

28

10
10
10

19
ans = 0
digits = [1, 9

digits = [1, 10]
ans = 10

ans = 20

[1,9,9]
100

[1,10,9]
200
[1,10,19]
219

199
0,10,9 100
0,0,19 200
0,0,0,2 219
'''

# sys.stdin = open("backforth.in", "r")
# sys.stdout = open("backforth.out", "w")

def solve():
  t = II()
  for _ in range(t):
    s = I().strip()
    digits = [0] * len(s)
    for i,num in enumerate(s):
       digits[i] = int(num)
    
    ans = 0
    for i in range(len(digits)-1):
      digits[i+1] += digits[i]
      ans += digits[i] * (10 ** (len(digits) - 1 - i))
    
    new_digits = []
    for d in str(digits[-1]):
       new_digits.append(int(d))
    
    # print(new_digits)
    for i in range(len(new_digits)):
       if i+1 < len(new_digits):
          new_digits[i+1] += new_digits[i]
       ans += new_digits[i] * (10 ** (len(new_digits) - 1 - i))
    # print(new_digits)
    ans += new_digits[-1] // 10
    print(ans)

solve() 