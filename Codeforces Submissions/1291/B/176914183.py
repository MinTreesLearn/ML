def solve(arr,n):
    k=0
    flag=True
    for i in range(n):
        if(arr[i]<i):
            break
        k=i
        
    for i in range(n-k):
        if(arr[n-1-i]<i):
            flag= False
            break
            
    return flag
        
        
        
t=int(input())
while(t>0):
    n=int(input())
    l=list(map(int,input().split()))
    if(solve(l,n)):
        print('YES')
    else:
        print('NO')
    t-=1