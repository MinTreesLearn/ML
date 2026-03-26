import sys
import math
import itertools
     
n,m=map(int,input().split())
init=[1]
for i in range(1,n):
    if(m==0):
        break
    pairs=i//2
    if(m>=pairs):
        m-=pairs
        init.append(i+1)
    else:
        init.append(i+1+2*(pairs-m))
        m=0
if(m!=0):
    print(-1)
    sys.exit()
nxt=10000000+6000
while(len(init)<n):
    init.append(nxt)
    nxt+=6000
for i in init:
    print(i,end=" ")