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


'''

def solve():
    t = II()
    for _ in range(t):
        n = II()
        s = I().strip()
        s += "A"

        ans = 0
        l = -1
        for i,c in enumerate(s):
            if c == "A":
                if l != -1:
                    ans = max(ans, i-l-1)
                l = i
        print(ans)

solve()