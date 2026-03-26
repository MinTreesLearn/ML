import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
q,x=map(int,input().split())
cant = [0]*(x+5)
res=0
for i in range (q):
    val = int (input())
    val %=x
    cant[val]+=1
    while cant[res%x]>0:
        cant[res%x]-=1
        res+=1
    print(res)