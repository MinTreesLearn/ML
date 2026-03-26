t=int(input())
for i in range(t):
    n,d=[int(j) for j in input().split()]
    a=[int(j) for j in input().split()]
    i=1
    while d>0 and i<n:
        if a[i]>0:
            a[0]+=1
            a[i]-=1
            d-=i
        else :
            i+=1
    if d>=0:
        print(a[0])
    else :
        print(a[0]-1)