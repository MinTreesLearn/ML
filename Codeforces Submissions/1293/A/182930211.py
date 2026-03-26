for _ in range(int(input())):
    n,s,k=map(int,input().split())
    arr=set(el for el in list(map(int,input().split())))
    start=s
    c=0
    while start<=s and start in arr:
        start-=1
        c+=1
    start1=s
    while start1>=s and start1 in arr:
        start1+=1
        c-=1
    if start!=0:
        if start1==n+1:
            print(s-start)
        elif c>0:
            print(start1-s)
        else:
            print(s-start)
    else:
        print(start1-s)
            