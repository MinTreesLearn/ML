#OMM NAMH SHIVAY
#JAI SHREE RAM
import sys,math,heapq,queue
from collections import deque
from functools import cmp_to_key
fast_input=sys.stdin.readline 
MOD=10**9+7
x0,y0,ax,ay,bx,by=map(int,fast_input().split()) 
xs,ys,t=map(int,fast_input().split())
temp=[[x0,y0]] 
while True:
    curx=ax*temp[-1][0]+bx 
    cury=ay*temp[-1][1]+by 
    if curx>=xs and cury>=ys and abs(curx-xs)+abs(cury-ys)>t:
        break 
    temp.append([curx,cury])

ans=0 
for i in range(len(temp)):
    lastx,lasty=xs,ys 
    c=0
    cur=0
    for j in range(i,len(temp)):
        cur+=abs(temp[j][0]-lastx)+abs(temp[j][1]-lasty)
        if cur>t:
            break
        c+=1 
        lastx,lasty=temp[j][0],temp[j][1]
    ans=max(ans,c)
for i in range(len(temp)-1,-1,-1):
    lastx,lasty=xs,ys 
    c=0
    cur=0
    for j in range(i,-1,-1):
        cur+=abs(temp[j][0]-lastx)+abs(temp[j][1]-lasty)
        if cur>t:
            break
        c+=1 
        lastx,lasty=temp[j][0],temp[j][1]
    ans=max(ans,c)

print(ans)

