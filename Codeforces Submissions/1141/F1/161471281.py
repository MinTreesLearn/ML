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
    n=int(input())
    arr=list(map(int, input().split()))
    pref=[0]*n
    prev=0
    for i in range(n):
        pref[i]=prev+arr[i]
        prev=pref[i]
    dic={}
    for i in range(n):
        for j in range(i,n):
            a=0
            if(i!=0):
                a=pref[i-1]
            if((pref[j]-a) in dic):
                dic[pref[j]-a].append([j+1,i+1])
            else:
                dic[pref[j]-a]=[[j+1,i+1]]
    ans=0
    curr=-1
    for i in dic:
        dic[i].sort()
        lis=dic[i]
        temp=[lis[0]]
        k=len(lis)
        ed=lis[0][0]
        for j in range(1,k):
            if(lis[j][1]>ed):
                ed=lis[j][0]
                temp.append(lis[j])
        if(len(temp)>ans):
            ans=len(temp)
            curr=temp
    print(ans)
    for i in range(ans):
        curr[i].reverse()
        print(*curr[i])
main()
