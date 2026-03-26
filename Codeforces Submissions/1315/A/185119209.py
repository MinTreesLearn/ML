for _ in range(int(input(''))):
    k=list(map(int,input().split()))
    a,b,x,y=k[0],k[1],k[2],k[3]
    l=[(a-x-1)*b,a*(b-y-1),a*y,b*x]
    print(max(l))