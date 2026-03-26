n,m=map(int,input().split())
arr=[]
for _ in range(n):
    arr.append(list(map(int,input().split())))
l=0
a1=0
a2=0
r=10**10
def check(x):
    d=[-1 for _ in range(1<<m)]
    for i,el in enumerate(arr):
        curr=0
        for j in range(m):
            if el[j]>x:
                curr|=(1<<j)
        d[curr]=i
    if d[-1]!=-1:
        a1=d[-1]
        a2=d[-1]
        return True,a1,a2
    for  i in range(1<<m):
        for j in range(1<<m):
            if d[i]!=-1 and d[j]!=-1 and (i|j)==len(d)-1:
                a1=d[i]
                a2=d[j]
                return True,a1,a2
    return False,-1,-1
    

while l<=r:
    mid=(l+r)//2
    p,i,j=check(mid)
    if p:
        a1=i
        a2=j
        ans=mid
        l=mid+1
    else:
        r=mid-1
print(a1+1,a2+1)