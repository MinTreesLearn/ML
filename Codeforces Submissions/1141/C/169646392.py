n=int(input())
arr=list(map(int,input().split()))
res=[]
a=0
b=0
temp=0
for el in arr:
    temp+=el
    a=min(a,temp)
    b=max(b,temp)
el=-a+1
level=b
if el+level==n:
    res.append(el)
    for el in arr:
        res.append(res[-1]+el)
    if len(set(res))!=n:
        print(-1)
    else :
        
        print(*res)
else:
    print(-1)