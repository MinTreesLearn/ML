n,m=map(int,input().split())
Q=[[]for _ in range(n)]
for _ in range(m):
    u,v=map(int,input().split())
    u-=1
    v-=1
    Q[v].append(u)
k=int(input())
p=[int(T)-1 for T in input().split()]
W=[-1]*n
E=[0]*n
q=[(p[-1],0)]
for u,d in q:
    if W[u]<0:
        W[u]=d
        d+=1
        for v in Q[u]:
            q.append((v,d))
    elif W[u]==d:
        E[u]+=1
R=S=0
for i in range(1,k):
    u,v=p[i-1],p[i]
    if W[u]<=W[v]:
        R+=1
        S+=1
    elif E[u]:
        S+=1
print(R,S)