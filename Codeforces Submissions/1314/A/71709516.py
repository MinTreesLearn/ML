import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))
T=list(map(int,input().split()))

from collections import defaultdict

D=defaultdict(list)
#S=defaultdict(int)
F=defaultdict(int)

for i in range(n):
    D[A[i]].append(-T[i])
    #S[A[i]]+=T[i]

KEYS=list(D.keys())
KEYS.sort()

rest=0
ANS=0

import heapq

for k in KEYS:
    if rest+len(D[k])<=1:
        continue
    if F[k]==1:
        continue

    H=list(D[k])
    nowk=k
    SUM=-sum(H)
    heapq.heapify(H)
    while len(H)>=2:
        x=heapq.heappop(H)
        SUM+=x
        ANS+=SUM

        #print(nowk,H,ANS,SUM)
        
        F[nowk]=1
        nowk+=1
        
        for dk in D[nowk]:
            heapq.heappush(H,dk)
            SUM+=-dk

        #print(nowk,H,ANS,SUM)

        

print(ANS)
        
        

    

    
    
    
