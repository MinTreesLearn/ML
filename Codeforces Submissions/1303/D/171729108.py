from math import log2
for _ in range(int(input())):
    n,m=map(int,input().split())
    arr=list(map(int,input().split()))
    c=[0]*(65)
    s=0
    for  el in  arr:
        c[int(log2(el))]+=1
        s+=el
    if s<n:
        print(-1)
        continue
    i=0
    res=0
    while i<60:
        if (n&(1<<i))!=0:
            if c[i]>0:
                c[i]-=1
            else :
                while i<60 and c[i]==0:
                    i+=1
                    res+=1
                c[i]-=1
                continue
        c[i+1]+=c[i]//2
        i+=1
    print(res)