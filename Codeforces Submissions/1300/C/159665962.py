n=int(input())
arr=list(map(int,input().split()))
f=False
for ind in range(32,-1,-1):
    c=0
    for el in arr:
        if (el>>ind)&1:
            c+=1
    if c==1:
        f=True
        break
if f:
    res=[]
    for i,el in enumerate(arr):
        if (el>>ind)&1:
            res.append(el)
            j=i
            break
    for i in range(n):
        if i!=j:
            res.append(arr[i])
    print(*res)
else :
    print(*arr)