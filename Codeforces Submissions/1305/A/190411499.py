t=int(input())
while(t>0):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    
    for i in range(n):
        print(a[i],end=" ")
    print()
    for i in range(n):
        print(b[i],end=" ")
    print()
    t=t-1