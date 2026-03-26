import sys
input=sys.stdin.readline
def binary_index(ar,n):
    for idx in range(1,n):
        idx2=idx+(idx&(-idx))
        if (idx2<n):
            ar[idx2]+=ar[idx]
def update(inp,add,ar,n):
    while(inp<n):
        ar[inp]+=add
        inp+=(inp&(-inp))
def summation(inp,ar):
    ans=0
    while(inp):
        ans+=ar[inp]
        inp-=(inp&(-inp))
    return ans

n,m=map(int,input().split())
ar=list(map(int,input().split()))
dic={}
mi=[0]
ma=[0]
for i in range(1,n+1):
    mi.append(i)
    dic[i]=n-i+1
    ma.append(dic[i])

li=[0]*(n+m+1)
for i in range(1,n+1):
    li[i]=1

le=n+m+1

binary_index(li,le)
pointer=n+1

for i in range(m):
    nu=ar[i]
    mi[nu]=1
    ind=dic[nu]
    dic[nu]=pointer
    ma[nu]=min(ma[nu],summation(ind,li))
    update(ind,-1,li,le)
    update(pointer,1,li,le)
    pointer+=1
for i in range(1,n+1):
    ma[i]=min(ma[i],summation(dic[i],li))
for i in range(1,n+1):
    print(mi[i],n-ma[i]+1)