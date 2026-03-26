for i in range(int(input())):
    a,b=map(int,input().split())
    k=len(f"{b}")
    n=0
    for j in range(1,k+1):
        if 10**j-1<=b:
            n+=1
    print(a*n)