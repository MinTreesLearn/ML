
def main():
    
    n = int(input())
    a = readIntArr()
    
    st = []  # store (total, l, r)
    for i, x in enumerate(a):
        st.append((x, i, i))
        while len(st) >= 2:
            total2, l2, r2 = st.pop()
            total1, l1, r1 = st.pop()
            if total1 / (r1 - l1 + 1) >= (total1 + total2) / (r2 - l1 + 1):
                total3 = total1 + total2
                st.append((total3, l1, r2))
            else:
                st.append((total1, l1, r1))
                st.append((total2, l2, r2))
                break
    ans = []
    for total, l, r in st:
        avg = total / (r - l + 1)
        for _ in range(r - l + 1):
            ans.append(avg)
    multiLineArrayPrint(ans)
    
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