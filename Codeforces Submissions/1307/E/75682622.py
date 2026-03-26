import sys
input = sys.stdin.readline
from itertools import accumulate

mod=10**9+7

n,m=map(int,input().split())
G=list(map(int,input().split()))

CP=[[0]*(n+1) for i in range(n+1)]
for i in range(m):
    f,e=map(int,input().split())
    CP[f][e]+=1
    
SUMCP=[]
for i in range(n+1):
    SUMCP.append(list(accumulate(CP[i])))

SUM=[0]*(n+1)
LAST=[]

for g in G:
    LAST.append(g)
    SUM[g]+=1

MAX=0
ANS=0
PLUS=1

for j in range(n+1):
    if SUM[j]>0 and SUMCP[j][SUM[j]]>0:
        PLUS=PLUS*SUMCP[j][SUM[j]]%mod
        MAX+=1

ANS=PLUS
MAX0=MAX

def PLUSVALUE(j):
    PLUS=1
    MAXC=0
    
    if cr[j]>=num_g:
        if SUMCP[j][cr[j]]>1:
            MAXC+=1
            PLUS=PLUS*(SUMCP[j][cr[j]]-1)%mod
    else:
        if SUMCP[j][cr[j]]>=1:
            MAXC+=1
            PLUS=PLUS*SUMCP[j][cr[j]]%mod
            
    return PLUS,MAXC
    

def OPLUSVALUE(j):    
    PLUS=1
    MAXC=0
    x,y=LEFT[j],cr[j]
    if x>y:
        x,y=y,x

    if SUMCP[j][x]==SUMCP[j][y]==1:
        MAXC+=1
        PLUS=PLUS*2%mod
        
    else:
        if SUMCP[j][x]>=1:
            MAXC+=2
            PLUS=PLUS*SUMCP[j][x]*(SUMCP[j][y]-1)%mod
                
        elif SUMCP[j][y]>=1:
            MAXC+=1
            PLUS=PLUS*SUMCP[j][y]%mod
            
    return PLUS,MAXC

LEFT=[0]*(n+1)

g=LAST[0]
LEFT[g]+=1
num_g=LEFT[g]

PLUS=CP[g][num_g]
OPLUS=1
if CP[g][num_g]==0:
    flag=0
    MAXC=0
else:
    flag=1
    MAXC=1

cr=SUM
cr[g]-=1

for j in range(n+1):
    if j==g:
        v,p_m=PLUSVALUE(g)
        
        PLUS=PLUS*v%mod
        MAXC+=p_m
    else:
        v,m=OPLUSVALUE(j)
        
        OPLUS=OPLUS*v%mod
        MAXC+=m

if MAXC>MAX and flag==1:
    MAX=MAXC
    ANS=PLUS*OPLUS%mod

elif MAXC==MAX and flag==1:
    ANS+=PLUS*OPLUS%mod

if flag==1:
    MAXC-=1+p_m
else:
    MAXC-=p_m


for i in range(1,n):
    #print("!",i,MAX,MAXC,ANS)
    g=LAST[i]
    past_g=LAST[i-1]
    v0,m0=OPLUSVALUE(past_g)
    v2,m2=OPLUSVALUE(g)
    
    OPLUS=OPLUS*v0*pow(v2,mod-2,mod)%mod
    MAXC+=m0-m2
    
    LEFT[g]+=1
    num_g=LEFT[g]
    cr[g]-=1

    #print(LEFT,cr,MAXC,PLUS,OPLUS)

    if CP[g][num_g]==0:
        continue
    else:
        PLUS=CP[g][num_g]
        MAXC+=1

    v,p_m=PLUSVALUE(g)

    PLUS=PLUS*v%mod
    MAXC+=p_m

    if MAXC>MAX:
        MAX=MAXC
        ANS=PLUS*OPLUS%mod

    elif MAXC==MAX:
        ANS+=PLUS*OPLUS%mod

    #print(LEFT,cr,MAXC,PLUS,OPLUS)
    MAXC-=1+p_m


print(MAX,ANS%mod)

        
                

            
                    

    

    
    
    
