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
 101
 110

1011

a+b = a xor b + 2*(a and b)

 1
11

10
11

11
 1

100
101

11011111101010010
'''

def solve():
    t = II()
    for _ in range(t):
        a = I().strip()
        b = I().strip()
        c = I().strip()

        valid = True
        for i in range(len(a)):
            if not (c[i] == a[i] or c[i] == b[i]):
                valid = False
                break

        print("YES" if valid else "NO")

solve()
