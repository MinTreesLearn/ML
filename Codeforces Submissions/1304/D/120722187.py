import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
t=int(input())
for w in range(t):
    n,s=(i for i in input().split())
    n=int(n)
    s=list(s)
    ans1=[0]*n
    ans2=[0]*n
    k=n
    prev=-1
    for i in range(n):
        if(i==n-1 or s[i]=='>'):
            for j in range(i,prev,-1):
                ans1[j]=k
                k-=1
            prev=i
    k=1
    prev=-1
    for i in range(n):
        if(i==n-1 or s[i]=='<'):
            for j in range(i,prev,-1):
                ans2[j]=k
                k+=1
            prev=i
    print(*ans1)
    print(*ans2)