def find_nextmax(arr,x):
    for i in range(len(arr)):
        if arr[i]>x:
            y=arr[i]
            arr[i]=0
            return y
    return -1
for _ in range(int(input())):
    n=int(input())
    b=list(map(int,input().split()))
    a=[]
    for i in range(2*n):
        if i%2==0:
            a.append(b[i//2])
        else:
            a.append(0)
    c=[i for i in range(1,2*n+1)]
    for i in range(0,2*n,2):
        c[a[i]-1]=0
    possible=True
    # print(a,c)
    # print(find_nextmax(c,5))
    # print(c)
    # print(a,c)
    for i in range(1,2*n,2):
        
        x=find_nextmax(c,a[i-1])
        if x==-1:
            possible=False
            break
        a[i]=x
        # print(a,c)   
    if not possible:
        print(-1)
        continue
    for i in a:
        print(i,end=' ')
    print()

    
                    