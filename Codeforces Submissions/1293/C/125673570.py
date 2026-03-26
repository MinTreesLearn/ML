# -*- coding: utf-8 -*-
"""
Created on Thu Aug 12 18:05:29 2021

@author: _ForeRunner_
"""

n,q=map(int,input().split())
a=[[0 for j in range(n+2)] for i in range(2)]
x=0
for i in range(q):
    n1,m=map(int,input().split())
    n1-=1
    if a[n1][m]==0:
       a[n1][m]=1
       if n1==1:
          n1=0
       else:
          n1=1
       if a[n1][m+1]==1:
           x+=1
       if a[n1][m]==1:
           x+=1
       if a[n1][m-1]==1:
           x+=1
    else:
        a[n1][m]=0
        if n1==1:
           n1=0
        else:
           n1=1
        if a[n1][m-1]==1:
            x-=1
        if a[n1][m]==1:
           x-=1
        if a[n1][m+1]==1:
            x-=1
    if x==0:
        print("Yes")
    else:
        print("No")
        