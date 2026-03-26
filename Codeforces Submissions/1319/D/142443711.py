from collections import deque
n,m=map(int,input().split())
mas=[0]*(n+1)
d=[0]*(n+1)
for i in range(n+1):
    mas[i]=[]
    d[i]=[10**6,0]
for i in range(m):
    a,b=map(int,input().split())
    mas[b].append(a)
k=int(input())
p=list(map(int,input().split()))
start=p[0]
finish=p[-1]
q=deque()
q.append(finish)
d[finish]=[0,0]
while q:
    v=q.popleft()
    for i in range(len(mas[v])):
        if d[v][0]+1<d[mas[v][i]][0]:
            q.append(mas[v][i])
            d[mas[v][i]][0]=d[v][0]+1
            d[mas[v][i]][1]=1
        elif d[v][0]+1==d[mas[v][i]][0]:
            d[mas[v][i]][1]+=1
#print(d)
minp=0
maxp=0
x=0
for i in range(1,k-1):
    if d[p[i-1]][0]-d[p[i]][0]!=1:
        minp+=1
        maxp+=1
    elif d[p[i-1]][1]>1:
        maxp+=1        
print(minp,maxp)

