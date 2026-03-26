import sys
input = sys.stdin.readline
from math import sqrt
import random

n=int(input())
A=list(map(int,input().split()))

random.shuffle(A)
MOD={2,3,5}

USED=set()
for t in A[:31]:
    if t in USED:
        continue
    else:
        USED.add(t)
    for x in [t-1,t,t+1]:
        if x<=5:
            continue
        L=int(sqrt(x))

        for i in range(2,L+2):
            while x%i==0:
                MOD.add(i)
                x=x//i
            if x==1:
                break

        if x!=1:
            MOD.add(x)

ANS=1<<29
for m in MOD:
    SCORE=0
    for a in A:
        if a<=m:
            SCORE+=m-a
        else:
            SCORE+=min(a%m,(-a)%m)
        if SCORE>=ANS:
            break
    else:
        ANS=SCORE

print(ANS)
            
            
    
    
