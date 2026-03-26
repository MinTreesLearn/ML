#  If you win, you live. You cannot win unless you fight.
from math import  sin
from sys import stdin,setrecursionlimit
input=stdin.readline
import heapq
rd=lambda: map(lambda s: int(s), input().strip().split())
ri=lambda: int(input())
rs=lambda :input().strip()
from collections import defaultdict as unsafedict,deque,Counter as unsafeCounter
from bisect import bisect_left as bl, bisect_right as br
from random import randint
random = randint(1, 10 ** 9)
mod=998244353
def ceil(a,b):
    return (a+b-1)//b
class myDict:
    def __init__(self,func):
        self.RANDOM = randint(0,1<<32)
        self.default=func
        self.dict={}
    def __getitem__(self,key):
        myKey=self.RANDOM^key
        if myKey not in self.dict:
            self.dict[myKey]=self.default()
        return self.dict[myKey]
    def get(self,key,default):
        myKey=self.RANDOM^key
        if myKey not in self.dict:
            return default
        return self.dict[myKey]
    def __setitem__(self,key,item):
        myKey=self.RANDOM^key
        self.dict[myKey]=item
    def getKeys(self):
        return [self.RANDOM^i for i in self.dict]
    def __str__(self):
        return f'{[(self.RANDOM^i,self.dict[i]) for i in self.dict]}'
from math import prod
'''
x*ts+y==m
(m-y)%ts==0
type 2
x*ts-x==m

'''
def samepar(a,b):
    return (a>=0 and b>=0) or (a<=0 and b<=0)
for _ in range(ri()):
    n,m=rd()
    s=rs()
    ts=s.count("0")-s.count("1")
    if ts==0:
        x=0
        ans=0
        for i in s:
            if i=="0":
                x+=1
            else:
                x-=1
            if x==m:
                ans+=1
        if ans:
            print(-1)
        else:
            print(0)
        continue
    ans=0
    y=0
    st=set()
    if (m%ts)==0 and samepar(m,ts) :
        # print("here ",m ,ts)
        st.add((m//ts,n-1))
    for i in range(n-1):
        if s[i]=="1":
            y-=1
        else:
            y+=1
        if (m-y)%ts==0:
            if (m-y)//ts>=0:
                # print(m - y, y, (m - y) // ts)
                st.add(((m-y)//ts,i))
            ans+=1
    # print(st)
    print(len(st))

       				 	  				     			 	