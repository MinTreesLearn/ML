from collections import deque
n,m=map(int,input().split())
h=dict()
for i in range( m):
    u,v=map(int,input().split())
    u-=1
    v-=1
    if v in h:
        h[v].append(u)
    else:
        h[v]=[u]
k=int(input())
arr=[int(j)-1 for j in input().split()]
p=deque([arr[-1]])
h1=dict()
h1[arr[-1]]=1
E = [0] * n
while(p):
    for nd in h[p[0]]:
        if nd not in h1:
            p.append(nd)
            h1[nd]=h1[p[0]]+1
        else:
            if h1[p[0]]+1==h1[nd]:
                E[nd]+=1
    p.popleft()
R = S = 0
for i in range(1, k):
    u, v = arr[i - 1], arr[i]
    if u not in h1:
        h1[u]=-1
    if v not in h1:
        h1[v]=-1
    if h1[u] <= h1[v]:
        R += 1
        S += 1
    elif E[u]:
        S += 1
print(R, S)     



