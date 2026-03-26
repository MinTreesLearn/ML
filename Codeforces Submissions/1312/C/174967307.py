t=int(input())
while(t>0):
    
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    bit=[0 for i in range(60)]
    

    for x in l:
        for i in range(60):
            bit[i] += x%k
            x=x//k

    ans=True
    for i in bit:
        if(i>1):
            ans=False
            break

    if(ans):
        print('YES')
    else:
        print('NO')
    
    t-=1