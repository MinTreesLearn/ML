from collections import deque
n,m=map(int,input().split())
r=[[] for i in range(n+1)]
for _ in range(m):
    x,y=map(int,input().split())
    r[y].append(x)
k=int(input())
path=list(map(int,input().split()))

d=[]
for i in range(n+1):
    d.append([10**6,0])

que=deque()
que.append([path[-1],0])
while que:
    node,dist=que.popleft()
    for i in r[node]:
        if d[i][0]>dist+1:
            d[i][0]=dist+1
            d[i][1]=1
            que.append([i,dist+1])
        elif d[i][0]==dist+1:
            d[i][1]+=1
miN=0
maX=0
for i in range(1,len(path)-1):
    if d[path[i-1]][0]-d[path[i]][0]!=1:
        miN+=1
        maX+=1
    elif d[path[i-1]][1]>1:
        maX+=1
print(miN,maX)
            

    
