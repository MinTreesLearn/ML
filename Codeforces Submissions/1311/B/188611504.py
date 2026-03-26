T=int(input(''))
while(T>0):
    [n,m]=list(map(int,input('').split()))
    arr=list([int(x) for x in input('').split()])
    arr2=[0]*n
    vis=[0]*n
    for i in range(0,n):
        arr2[i]=arr[i]
    vis=[0]*n
    arr2.sort()
    temp=list(int(x) for x in input('').split())
    for i in temp:
        i=i-1
        vis[i]=1
    i,f=n-1,0
    while(i>-1):
        if(arr[i] != arr2[i]):
            j=i-1
            while(j>-1 and arr[j]!=arr2[i]):
                j=j-1
            while(j<i):
                if(vis[j]==0):
                    f=1
                    break
                arr[j],arr[j+1]=arr[j+1],arr[i]
                j=j+1
        if(f):
            break
        i=i-1
    if(f):
        print("No")
    else:
        print("Yes")


    T-=1