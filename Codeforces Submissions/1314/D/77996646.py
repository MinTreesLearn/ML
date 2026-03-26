import sys
input = sys.stdin.readline
from random import randint

n,T=map(int,input().split())
COST=[list(map(int,input().split())) for i in range(n)]
ANS=1<<30

for tests in range(5*10**3):
    COLOR=[randint(0,1) for i in range(n)]
    COLOR[0]=0

    DP=[1<<30]*n
    DP[0]=0
    
    for trip in range(T):
        NDP=[1<<30]*n
        
        if trip%2==0:
            for j in range(n):
                if COLOR[j]==1:
                    continue
                for k in range(n):
                    if j!=k and COLOR[k]==1:
                        NDP[k]=min(NDP[k],DP[j]+COST[j][k])

        else:
            for j in range(n):
                if COLOR[j]==0:
                    continue
                for k in range(n):
                    if j!=k and COLOR[k]==0:
                        NDP[k]=min(NDP[k],DP[j]+COST[j][k])

        DP=NDP
        #print(DP)

    #print(DP,COLOR)

    ANS=min(ANS,DP[0])
print(ANS)
    
            
            

