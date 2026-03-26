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
    n,k=map(int,input().split())
    dic={}
    graph=[[0,i] for i in range(n)]
    for i in range(n-1):
        u,v=map(int,input().split())
        u-=1
        v-=1
        dic[(u,v)]=[i]
        graph[u].append(v)
        graph[u][0]+=1
        graph[v].append(u)
        graph[v][0]+=1
    graph.sort(reverse=True)
    unf=[0]*n
    temp=[0]*n
    for i in range(n):
        if(i<k):
            unf[graph[i][1]]=1
        temp[graph[i][1]]=graph[i][2:]
    graph=temp
    curr=0
    stk=[curr]
    vis=[-1]*n
    vis[0]=0
    ma=-1
    while(stk!=[]):
        f=stk.pop()
        if(unf[f]):
            if(f==0):
                col=1
            else:
                if((f,vis[f]) in dic):
                    col=dic[(f,vis[f])][1]
                else:
                    col=dic[(vis[f],f)][1]
            for i in graph[f]:
                if(vis[i]!=-1):
                    continue
                vis[i]=f
                if((i,f) in dic):
                    dic[(i,f)].append(col)
                else:
                    dic[(f,i)].append(col)
                stk.append(i)
        else:
            st=1
            avoid=-1
            if(f!=0):
                if((f,vis[f]) in dic):
                    avoid=dic[(f,vis[f])][1]
                else:
                    avoid=dic[(vis[f],f)][1]
            for i in graph[f]:
                if(vis[i]!=-1):
                    continue
                vis[i]=f
                if(st==avoid):
                    st+=1
                if((i,f) in dic):
                    dic[(i,f)].append(st)
                else:
                    dic[(f,i)].append(st)
                ma=max(ma,st)
                st+=1
                stk.append(i)
    ans=[0]*(n-1)
    for i in dic:
        ans[dic[i][0]]=dic[i][1]
    ma=max(ma,1)
    print(ma)
    print(*ans)
main()
