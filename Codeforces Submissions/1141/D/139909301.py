#from itertools import *
#from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *
#from heapq import *
#from itertools import *            # Things Change ....remember :)
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
def func(a,b,c):
    z1=min(len(a),len(b))
    for i in range(z1):
        c.append([a.pop(),b.pop()])
t=1
while(t):
    t-=1
    n=inp()
    q1=[]
    q2=[]
    s=st()
    s1=st()
    r=[]
    id1=[[] for i in range(26)]
    id2=[[] for i in range(26)]
    for i in range(n):
        z=ord(s[i])-97
        z1=ord(s1[i])-97
        if(s[i]!='?'):
            id1[z].append(i+1)
        else:
            q1.append(i+1)
        if(s1[i]!='?'):
            id2[z1].append(i+1)
        else:
            q2.append(i+1)
    for i in range(26):
        func(id1[i],id2[i],r)
    for i in range(26):
        func(id1[i],q2,r)
        func(q1,id2[i],r)
    func(q1,q2,r)
    print(len(r))
    for i in r:
        print(*i)
        
            
