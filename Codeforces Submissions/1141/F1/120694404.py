from itertools import*
from collections import*
n=int(input())
arr=[0] +[*accumulate(map(int,input().split()))]
g=defaultdict(list)
for i in range(n):
    for j in range(i+1,n+1):
        g[arr[j] -arr[i]].append([i+1,j])
ans=[]
maxi=[]
for i in g:
    f=sorted(g[i],key=lambda x:x[1])
    ans=[f[0]]
    for l,r in f:
        if l >ans[-1][1]:
            ans.append([l,r])
    maxi=max(maxi,ans,key=len)
print(len(maxi))
for i in maxi:
    print(*i)