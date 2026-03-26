a=int(input())
z=list(map(int,input().split()))
r=list(map(int,input().split()))
ans=[]
for i in range(a):
    ans.append([z[i],r[i]])
ans.sort()
from heapq import *
i=0
pq=[]
ss=0
sol=0
while(i<len(z)):

    if(len(pq)==0):
        heappush(pq,-1*ans[i][1])
        ss+=ans[i][1]
        v=ans[i][0]
        i+=1
    while(i<len(ans) and ans[i][0]==v):
        heappush(pq,-ans[i][1])
        ss+=ans[i][1]
        i+=1
    ss+=heappop(pq)
    sol+=ss
    v+=1
while(pq):
    ss+=heappop(pq)
    sol+=ss
print(sol)
        
    
