n=int(input())
r1=list(map(int,input().split()))
r2=list(map(int,input().split()))
a=sum(r1)
b=sum(r2)
if a==b==0:
    print(-1)
elif a==b==n:
    print(-1)
else:
    p=0
    v=0
    for i in range(n):
        if r1[i]==0 and r2[i]==1:
            v+=1
        elif r1[i]==1 and r2[i]==0:
            p+=1
    if p==0:
        print(-1)
    elif v<p:
        print(1)
    elif v==p:
        print(2)
    else:
        minb=v-p+1
        print((minb+p-1)//p+1)
