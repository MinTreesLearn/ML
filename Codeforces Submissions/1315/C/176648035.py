for i in range(int(input())): 
    n=int(input())
    arr=list(map(int,input().split()))
    a=[]
    i=0
    t=0
    while(len(a)!=(2*n)):
        if(t==0): 
    
            r=arr[i]
            a.append(arr[i])
        if (r+1 not in arr) and (r+1 not in a):
            a.append(r+1)
            i+=1
            t=0
        else:
            r+=1
            t=1


    b=[]
    
    for i in a:
        b.append(i)
    c=[]
    
        
    b.sort()
    for i in range(2*n):
        c.append(i+1)
    if b!=c :
        print(-1)
    else: 
            
        print(*a)