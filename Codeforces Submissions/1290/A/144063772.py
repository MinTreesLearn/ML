for _ in range(int(input())):
    n,m,k=map(int,input().split())
    a=list(map(int,input().split()))
    if k>=m:
        ans=0
        for i in range(m):
            ans=max(ans,a[i],a[n-i-1])
        print(ans)
    else:
        bmax=0
        for x in range(k+1):
            bmin=float('inf')
            for y in range(m-k):
                b=max(a[x+y],a[x+y+n-m])
                bmin=min(bmin,b)
            bmax=max(bmax,bmin)
        print(bmax)



