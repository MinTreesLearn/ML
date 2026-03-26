n=int(input())
q=list(map(int,input().split()))
q=[0]+q
qs=[0]
qss=[0]
for i in range(1,n):

    qs.append(qs[i-1]+q[i])
    qss.append(qss[i-1]+qs[i])

if ((1+n)*n/2-qss[n-1])%n!=0:
    print(-1)
else:
    table=[0 for i in range(1+n)]
    p=[0 for i in range(1+n)]
    p[1]=int(((1+n)*n/2-qss[n-1])/n)
    if p[1] >= 1 and p[1] <= n:
        table[p[1]]=1
    else:
        print(-1)
        exit(0)
    for i in range(2,n+1):
        p[i]=q[i-1]+p[i-1]
        if p[i]>=1 and p[i]<=n:
            table[p[i]]+=1
        else:
            print(-1)
            exit(0)
    flag=1
    for i in range(1,n+1):
        if table[i]!=1:
            flag=0
    if flag==1:
        for i in range(1,n):
            print(p[i],end=" ")
        print(p[n])
    else:
        print(-1)
