import sys
input = sys.stdin.readline
from collections import deque

N=int(input())
E=[[] for i in range(N+1)]

for i in range(N-1):
    x,y=map(int,input().split())
    E[x].append(y)
    E[y].append(x)

Q=deque()

USE=[0]*(N+1)
Q.append(1)
H=[0]*(N+1)
H[1]=1
USE[1]=1
P=[-1]*(N+1)

QI=deque()

while Q:
    x=Q.pop()
    for to in E[x]:
        if USE[to]==0:
            USE[to]=1
            H[to]=H[x]+1
            P[to]=x
            Q.append(to)
            QI.append((x,to,to,x))
            P[to]=x
 
EH=[(h,ind+1) for ind,h in enumerate(H[1:])]
EH.sort(reverse=True)
 
COME=[1]*(N+1)
USE=[0]*(N+1)
 
for h,ind in EH:
    USE[ind]=1
    for to in E[ind]:
        if USE[to]==0:
            COME[to]+=COME[ind]

GO=[N-COME[i] for i in range(N+1)]
DP=[[0]*(N+1) for i in range(N+1)]
USE=[[0]*(N+1) for i in range(N+1)]

while QI:
    l,frl,r,frr=QI.pop()

    if P[l]==frl:
        A1=COME[l]
    else:
        A1=GO[frl]

    if P[r]==frr:
        A2=COME[r]
    else:
        A2=GO[frr]

    DP[l][r]=DP[r][l]=A1*A2+max(DP[frl][r],DP[l][frr])

    for to in E[l]:
        if to==frl or USE[to][r]==1:
            continue
        USE[to][r]=USE[r][to]=1
        QI.appendleft((to,l,r,frr))

    #for to in E[r]:
    #    if to==frr or USE[l][to]==1:
    #        continue
    #    USE[to][l]=USE[l][to]=1
    #    QI.append((l,frl,to,r))

ANS=0
for d in DP:
    ANS=max(ANS,max(d))

print(ANS)

    

