
def naive(n, a):
    xor = 0
    for i in range(n):
        for j in range(i + 1, n):
            xor ^= (a[i] + a[j])
    return xor

def main():
    
    n = int(input())
    a = readIntArr()
    
    m = 25
    # m = 4
    xorparity = [0] * m
    
    for twopow in range(m):
        base = 2 ** twopow
        a2 = [v % (base * 2) for v in a]
        a2.sort()
        # print('base:{} a2:{}'.format(base * 2, a2))
        
        for l, r in ((base, (base * 2) - 1),
                     (base + base * 2, base * 4 - 1)):
            LEFTPOINTER = RIGHTPOINTER = n
            for i in range(n):
                LEFTPOINTER = max(LEFTPOINTER, i + 1)
                RIGHTPOINTER = max(RIGHTPOINTER, i + 1)
                # search for l boundary
                while LEFTPOINTER - 1 >= i + 1 and a2[LEFTPOINTER - 1] >= l - a2[i]:
                    LEFTPOINTER -= 1
                LEFT = LEFTPOINTER
                # lo, hi = i, n - 1
                # while lo < hi:
                #     mid = (lo + hi + 1) // 2
                #     if a2[mid] < l - a2[i]:
                #         lo = mid
                #     else:
                #         hi = mid - 1
                # LEFT = lo + 1
                
                # search for r boundary
                while RIGHTPOINTER - 1 >= i + 1 and a2[RIGHTPOINTER - 1] > r - a2[i]:
                    RIGHTPOINTER -= 1
                RIGHT = RIGHTPOINTER - 1
                # lo, hi = i, n - 1
                # while lo < hi:
                #     mid = (lo + hi + 1) // 2
                #     if a2[mid] <= r - a2[i]:
                #         lo = mid
                #     else:
                #         hi = mid - 1
                # RIGHT = lo
                
                # print('twopow:{} l:{} r:{} base:{} i:{} LEFT:{} RIGHT:{}'.format(
                #     twopow, l, r, base, i, LEFT, RIGHT))
                xorparity[twopow] ^= ((RIGHT - LEFT + 1) % 2)
                
                
    
    ans = 0
    for twopow in range(m):
        ans += xorparity[twopow] * (2 ** twopow)
    print(ans)
    
    # assert ans == naive(n, a)
    
    return


import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(a, b):
    print('? {} {}'.format(a, b))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353
 
from math import gcd,floor,ceil
import math
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()