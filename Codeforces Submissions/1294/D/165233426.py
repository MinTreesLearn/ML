from bisect import *
from collections import *
import sys
import io, os
import math
import random
from heapq import *
gcd = math.gcd
sqrt = math.sqrt
maxint=10**21
def ceil(a, b):
    if(b==0):
        return maxint
    a = -a
    k = a // b
    k = -k
    return k
# arr=list(map(int, input().split()))
# n,m=map(int,input().split())

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def strinp(testcases):
    k = 5
    if (testcases == -1 or testcases == 1):
        k = 1
    f = str(input())
    f = f[2:len(f) - k]
    return f
def lcm(n):
    ans=1
    for i in range(2,n):
        ans=(ans*i)//(gcd(ans,i))
    return(ans)
def main():
    q,x=map(int,input().split())
    ct=[0]*(q+1)
    mex=0
    if(q<x):
        mex=0
        for i in range(q):
            g=int(input())
            g=g%x
            if(g>q):
                print(mex)
                continue
            ct[g]+=1
            while(ct[mex]):
                mex+=1
            print(mex)
        return
    groups=[0 for i in range(x)]
    for i in range(q):
        g=int(input())
        g=g%x
        ind=g+(groups[g]*x)
        if(ind<=q):
            ct[ind]+=1
            groups[g]+=1
        while(ct[mex]):
            mex+=1
        print(mex)
main()