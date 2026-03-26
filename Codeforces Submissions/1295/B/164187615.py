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
# arr=list(map(int, input().split()))if(n==1):
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
    T=int(input())
    for _ in range(T):
        n,x=map(int,input().split())
        s=strinp(90)
        z=0
        o=0
        b=[0]*n
        for i in range(n):
            if(s[i]=="0"):
                z+=1
            else:
                o+=1
            b[i]=z-o
        if(b[-1]==0):
            trig=False
            for i in range(n):
                if(b[i]==x):
                    trig=True
                    break
            if(trig):
                print(-1)
            else:
                print(0)
            continue
        ans=int((x%b[-1]==0) and ((x//b[-1])>=0))
        for i in range(n-1):
            g=x-b[i]
            if(g%b[-1]==0 and g//b[-1]>=0):
                ans+=1
        print(ans)
main()