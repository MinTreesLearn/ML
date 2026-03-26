import sys
input = sys.stdin.readline

n=int(input())
T=[input().split() for i in range(n)]
k=int(input())
S=list(map(int,input().split()))
SETS=set(S)

E=[[] for i in range(n+1)]
P=[-1]*(n+1)

for i in range(n):
    p,s=T[i]
    p=int(p)
    E[p].append((s,i+1))
    P[i+1]=p

for i in range(n+1):
    E[i].sort(reverse=True)

ELI=[0]*(n+1)
DEPTH=[0]*(n+1)
ELIMIN=[0]*(n+1)
ANS=[0]*(n+1)

Q=[0]
USED=[0]*(n+1)
count=0
while Q:
    x=Q.pop()
    USED[x]=1
    if x in SETS:
        count+=1
    #print(x,count)

    if x in SETS:
        ANS[x]=min(DEPTH[x],count+ELIMIN[P[x]],ANS[P[x]]+1)
        ELI[x]=ANS[x]-count+1
    else:
        ANS[x]=min(DEPTH[x],ANS[P[x]]+1)
        ELI[x]=ANS[x]-count

    ELIMIN[x]=min(ELI[x],ELIMIN[P[x]])
        
    
    for s,to in E[x]:
        if USED[to]==1:
            continue
        
        Q.append(to)
        DEPTH[to]=DEPTH[x]+1


print(*[ANS[s] for s in S])
        
        
        


