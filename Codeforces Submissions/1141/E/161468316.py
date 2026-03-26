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
    H,n=map(int,input().split())
    d=list(map(int, input().split()))
    pref=[0]*(n)
    prev=0
    ans=-1
    for i in range(n):
        pref[i]=d[i]+prev
        prev=pref[i]
        if(prev+H<=0):
            ans=i+1
            break
    if(ans!=-1):
        print(ans)
        return()
    tot=prev
    if(tot>=0):
        print(-1)
        return()
    tot=-tot
    mi=10**21
    for i in range(n):
        ans=(i+1)+((((H+pref[i])//tot)+min((H+pref[i])%tot,1))*n)
        mi=min(mi,ans)
    print(mi)
    
        
main()
