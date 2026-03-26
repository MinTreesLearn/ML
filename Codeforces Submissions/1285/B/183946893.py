for i in range(int(input())):
    n=int(input())
    values=list(map(int,input().split()))
    total=sum(values)
    su=0
    hey=0
    for val in values[:n-1]:
        su+=val
        if su<=0:
            print("NO")
            hey=1
            break
        elif su>=total:
            print("NO")
            hey=1
            break
    if hey==0 and values[n-1]>0:
        print("YES")