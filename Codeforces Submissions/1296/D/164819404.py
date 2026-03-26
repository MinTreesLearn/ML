from bisect import *
from collections import *
import sys
import io, os
import math
import random
import operator
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

def main():
    t=1
    for _ in range(t):
        n,a,b,k=map(int,input().split())
        h=list(map(int, input().split()))
        ct=0
        lis=[]
        for i in range(n):
            r=h[i]%(a+b)
            if(r<=a and r>0):
                ct+=1
                continue
            if(r==0):
                r=a+b
            reqd=ceil(r,a)-1
            if((h[i]-((reqd)*a)<0)):
                continue
            lis.append(reqd)
        lis.sort(reverse=True)
        while(lis!=[] and k>0):
            p=lis.pop()
            if(p>k):
                break
            ct+=1
            k-=p
        print(ct)
main()