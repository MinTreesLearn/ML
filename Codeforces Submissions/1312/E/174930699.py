
def main():
    
    n = int(input())
    a = readIntArr()
    
    dp = [[-1 for _ in range(n)] for __ in range(n)]
    # dp[l][r] = the value that a[l:r] can become
    for l in range(n):
        dp[l][l] = a[l]
    
    for gap in range(2, n + 1):
        for l in range(n):
            r = l + gap - 1
            if r == n:
                break
            for mid in range(l, r):
                if dp[l][mid] != -1 and dp[l][mid] == dp[mid + 1][r]:
                    dp[l][r] = dp[l][mid] + 1
                    break
    
    dp2 = [n] * n
    for r in range(n):
        for l in range(r + 1):
            if l == 0:
                prev = 0
            else:
                prev = dp2[l - 1]
            if dp[l][r] != -1:
                dp2[r] = min(dp2[r], prev + 1)
    ans = dp2[n - 1]
    print(ans)
    
    return


import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
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