a,b=map(int,input().split())
if a==b:
    print(0)
elif (a>b):
    print(-1)
else:
    c=0
    x=b/a
    while(x%2==0):
        x/=2
        c+=1
    while(x%3==0):
        x/=3
        c+=1
    print(c if x==1 else -1)