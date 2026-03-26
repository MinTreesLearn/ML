import sys
import math
import collections
import heapq
input=sys.stdin.readline
n=int(input())
s=list(input())
if(n==1):
    print(0)
else:
    s1=[]
    for i in range(n):
        s1.append(s[i])
    c=1
    ans=0
    while(c==1):
        m=-1
        ind=-1
        n1=len(s1)
        if(n1==1):
            break
        else:
            for i in range(n1):
                if(i==0):
                    if(ord(s1[i])-ord(s1[i+1])==1):
                        if(s1[i]!='a'):
                            ind=i
                            m=s1[i]
                elif(i==n1-1):
                    if(ord(s1[i])-ord(s1[i-1])==1):
                        if(s1[i]!='a'):
                            if(m==-1):
                                ind=i
                                m=s1[i]
                            else:
                                if(s1[i]>m):
                                    ind=i
                                    m=s1[i]
                else:
                    if(ord(s1[i])-ord(s1[i-1])==1 or ord(s1[i])-ord(s1[i+1])==1):
                        if(s1[i]!='a'):
                            if(m==-1):
                                ind=i
                                m=s1[i]
                            else:
                                if(s1[i]>m):
                                    ind=i
                                    m=s1[i]
        if(m==-1):
            c=0
        else:
            s2=[]
            for i in range(n1):
                if(i!=ind):
                    s2.append(s1[i])
            s1=[]
            for i in range(n1-1):
                s1.append(s2[i])
            ans+=1
    print(ans)