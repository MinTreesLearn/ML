t=int(input())
for _ in range(t):
    n,m,k=[int(x) for x in input().split(' ')]
    v=[int(x) for x in input().split(' ')]
    i,j=0,n-1
    k=min(k,m-1)
    kk=k
    mm=m
    ans=max(v)
    final=min(v)
    for x in range(0,k+1):
        ans=max(v)
        for y in range(0,m-k):
            ans=min(ans,max(v[x+y],v[n-1-(m-1-x-y)]))
        final=max(final,ans)    
    print(final)