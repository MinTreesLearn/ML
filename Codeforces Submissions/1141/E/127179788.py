from math import ceil
H,n=map(int,input().split())
array=list(map(int,input().split()))
cumsum=[array[0]]
minm=array[0]
for i in range(1,n):
    val=cumsum[-1]+array[i]
    minm=min(minm,val)
    cumsum.append(val)
if cumsum[-1]>=0:
    if minm+H>0:
        print(-1)
    else:
        for i in range(n):
            if cumsum[i]+H<=0:
                print(i+1)
                break
else:
    v=H+minm
    if v<=0:
        for i in range(n):
            if cumsum[i] + H <= 0:
                print(i + 1)
                break
    else:
        round=ceil(v/(cumsum[-1]*(-1)))
        ans=H+(cumsum[-1]*round)
        for i in range(n):
            if cumsum[i]+ans<=0:
                print(n*round+i+1)
                break