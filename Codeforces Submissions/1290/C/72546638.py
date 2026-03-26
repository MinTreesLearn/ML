import sys
input = sys.stdin.readline

n,k=map(int,input().split())
S=[1]+list(map(int,list(input().strip())))
C=[]

for i in range(k):
    c=int(input())
    C.append(list(map(int,input().split())))

NUM=[[] for i in range(n+1)]

for i in range(k):
    for c in C[i]:
        NUM[c].append(i)

COLORS=[-1]*k
EDGE0=[[] for i in range(k)]
EDGE1=[[] for i in range(k)]

for i in range(1,n+1):
    if len(NUM[i])==1:
        if S[i]==0:
            COLORS[NUM[i][0]]=1
        else:
            COLORS[NUM[i][0]]=0

    elif len(NUM[i])==2:
        x,y=NUM[i]
        if S[i]==0:
            EDGE0[x].append(y)
            EDGE0[y].append(x)
        else:
            EDGE1[x].append(y)
            EDGE1[y].append(x)

Q=[i for i in range(k) if COLORS[i]!=-1]

while Q:
    x=Q.pop()
    for to in EDGE0[x]:
        if COLORS[to]==-1:
            COLORS[to]=1-COLORS[x]
            Q.append(to)

    for to in EDGE1[x]:
        if COLORS[to]==-1:
            COLORS[to]=COLORS[x]
            Q.append(to)

for i in range(k):
    if COLORS[i]==-1:
        COLORS[i]=0
        Q=[i]

        while Q:
            x=Q.pop()
            for to in EDGE0[x]:
                if COLORS[to]==-1:
                    COLORS[to]=1-COLORS[x]
                    Q.append(to)

            for to in EDGE1[x]:
                if COLORS[to]==-1:
                    COLORS[to]=COLORS[x]
                    Q.append(to)

#print(COLORS)

Group = [i for i in range(k)]
W0 = [0]*(k)
W1 = [0]*(k)

for i in range(k):
    if COLORS[i]==0:
        W0[i]=1
    else:
        W1[i]=1
    

def find(x):
    while Group[x] != x:
        x=Group[x]
    return x

def Union(x,y):
    if find(x) != find(y):
        if W0[find(x)] + W1[find(x)] < W0[find(y)] + W1[find(y)]:
            
            W0[find(y)] += W0[find(x)]
            W0[find(x)] =0

            W1[find(y)] += W1[find(x)]
            W1[find(x)] =0
            Group[find(x)] =find(y)

        else:

            W0[find(x)] += W0[find(y)]
            W0[find(y)] =0

            W1[find(x)] += W1[find(y)]
            W1[find(y)] =0
            Group[find(y)] =find(x)

ANS=0
SCORES=[0]*(k)
for i in range(1,n+1):
    if len(NUM[i])==0:
        True
        
    elif len(NUM[i])==1:
        x=NUM[i][0]

        ANS-=SCORES[find(x)]
        SCORES[find(x)]=0
        
        W0[find(x)]+=1<<31

        ANS+=W1[find(x)]
        SCORES[find(x)]=W1[find(x)]

    else:
        x,y=NUM[i]
        ANS-=SCORES[find(x)]
        SCORES[find(x)]=0
        ANS-=SCORES[find(y)]
        SCORES[find(y)]=0
        
        if find(x)!=find(y):
            Union(x,y)

        SCORES[find(x)]+=min(W0[find(x)],W1[find(x)])
        ANS+=min(W0[find(x)],W1[find(x)])

    print(ANS)
