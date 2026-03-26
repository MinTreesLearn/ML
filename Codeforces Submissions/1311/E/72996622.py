from math import ceil,floor,log
t=int(input())
for i2 in range(t):
    n,d=map(int,input().split())
    p,dad=0,[0]*(n+1)
    c=(n*(n-1))//2
    for i in range(1,n+1):
        p+=floor(log(i,2))
    if p>d or c<d:
        print("NO")
        continue
    now=1
    dad=[0]*(n+1)
    vec=[[]for i in range(n+1)]
    for i in range(1,n+1):
        vec[i-1].append(i)
    for i in range(n,0,-1):
        if c-d<=i-1-now:
            vec[now].append(i)
            dad[i]=vec[i-2-(c-d)][(len(vec[i-(c-d)-1])+1)//2-1]
            break
        else:
            vec[now].append(i)
            dad[i]=vec[now-1][(len(vec[now])+1)//2-1]
            c-=i-1-now
            if len(vec[now])>=2**now:
                now+=1
    print("YES")
    for i in range(2,n+1):
        if dad[i]==0:
            print(i-1,end=" ")
        else:
            print(dad[i],end=" ")
    print("")