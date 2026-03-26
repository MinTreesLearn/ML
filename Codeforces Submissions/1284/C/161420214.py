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
    a = -a
    k = a // b
    k = -k
    return k
# arr=list(map(int, input().split()))
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def strinp(testcases):
    k = 5
    if (testcases == -1 or testcases == 1):
        k = 1
    f = str(input())
    f = f[2:len(f) - k]
    return f


def main():
    n,mod=map(int,input().split())
    facts=[1]*(n+1)
    for i in range(2,n+1):
        facts[i]=i*facts[i-1]
        facts[i]%=mod
    ans=0
    tot=0
    for i in range(1,n+1):
        p1=facts[n+1-i]
        p2=facts[i]
        ans+=((p1*p2)%mod)
        ans%=mod
        tot+=ans
        tot%=mod
    print(tot)
main()
