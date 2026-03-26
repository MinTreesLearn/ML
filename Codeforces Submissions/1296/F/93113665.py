#AUTHOR- titia

import sys
input = sys.stdin.readline
from operator import itemgetter

n=int(input())
EDGE=[sorted(map(int,input().split())) for i in range(n-1)]

E=[[] for i in range(n+1)]

D=dict()

for i in range(n-1):
    x,y=EDGE[i]
    D[(x<<13)+y]=i
    D[(y<<13)+x]=i
    E[x].append(y)
    E[y].append(x)

m=int(input())

Q=sorted([tuple(map(int,input().split())) for i in range(m)],key=itemgetter(2),reverse=True)
    
def dfs(x,y,n,w):
    USE=[-1]*(n+1)
    NOW=[x]
    
    while NOW:
        n=NOW.pop()
        if n==y:
            break

        for to in E[n]:
            if USE[to]==-1:
                USE[to]=n
                NOW.append(to)

    change=0
    while y!=x:
        p=D[(y<<13)+USE[y]]
        if ANS[p]<=w:
            change+=1
            ANS[p]=w
        y=USE[y]

    if change==0:
        print(-1)
        sys.exit()
        
ANS=[1]*(n-1)

for a,b,q in Q:
    dfs(a,b,n,q)
    flag=1

print(*ANS)
            
        
    
