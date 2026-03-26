for _ in range(int(input())):
    n,m,k=map(int,input().split())
    arr=list(map(int,input().split()))
    behind=n-m
    k=min(k,m-1)
    ans=0
    for i in range(k+1):
        p=float("inf")
        for j in range(m-k):
            # print(i,j,k)
            temp=max(arr[i+j],arr[n-1-(k-i)-(m-k-1-j)])
            p=min(p,temp)
        ans=max(ans,p)
    print(ans)