x=int(input())
for i in range(x):
    a=int(input())
    lis=list(map(int,input().split()))
    s=set(lis)
    lis=list(s)
    print(len(lis))