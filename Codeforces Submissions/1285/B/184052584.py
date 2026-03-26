# import sys
# sys.stdin = open('ip.txt','r')
# sys.stdout = open('op.txt','w')

import math
from bisect import *

R=lambda:map(int,input().split())
t,=R()
while t:
    t-=1;
    n, = R()
    arr = list(R())
    presum = 0;
    k1 =float('-inf')
    k2 =float('-inf')
    all_sum = sum(arr)
    s = 0; e = len(arr)
    # K(0,n-1)
    for i in range(len(arr)-1):
        if presum == 0:
            s = i
        presum+=arr[i]
        if presum > k1:
            e = i
            k1 = presum
        if presum < 0:
            presum = 0
    # K(1,n)
    presum = 0
    for i in range(1,len(arr)):
        if presum == 0:
            s = i
        presum+=arr[i]
        if presum > k2:
            e = i
            k2 = presum
        if presum < 0:
            presum = 0
    # max(k1,k2) 
    k = max(k1,k2)
    
    if all_sum > k:
        print('YES')
    else :
        print('NO')
    
        
    
        