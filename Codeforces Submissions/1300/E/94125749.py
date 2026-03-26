import os,io
import sys
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n=int(input())
a=list(map(int,input().split()))
sums=[0]
curr=0
t=[]
for i in range(n):
    curr+=a[i]
    sums.append(curr)
for i in range(n):
    t.append([i-1,i])
for i in range(1,n):
    while t[i][0]!=-1 and (sums[t[i][1]+1]-sums[t[i][0]+1])*(t[i][0]-t[t[i][0]][0])<(sums[t[i][0]+1]-sums[t[t[i][0]][0]+1])*(t[i][1]-t[i][0]):
        t[i][0]=t[t[i][0]][0]
i=n-1
ans=[]
while i>=0:
    k=str((sums[t[i][1]+1]-sums[t[i][0]+1])/(t[i][1]-t[i][0]))
    for j in range(t[i][1]-t[i][0]):
        ans.append(k)
    i-=t[i][1]-t[i][0]
ans.reverse()
print(' '.join(ans))