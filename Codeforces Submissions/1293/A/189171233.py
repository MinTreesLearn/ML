for _ in range(int(input())):
    n,s,k=map(int,input().split())
    ll=list(map(int,input().split()))
    m=(10**9)+1
    for t in range(max(1,s-1000),min(n+1,s+1001)):
        if t not in ll and abs(s-t)<m:
            m=abs(s-t)
    print(m)