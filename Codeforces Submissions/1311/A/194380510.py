T = int(input())
for _ in range(T):
    a,b = map(int,input().split())
    ans=0
    diff=0
    if(a==b):
        ans = 0
    elif(a>b):
        diff=a-b
        ans+= 1 
        if(diff%2!=0):
            ans+= 1 
    elif(a<b):
        diff=b-a
        ans+=1 
        if(diff%2!=1):
            ans+=1 
    print(ans)