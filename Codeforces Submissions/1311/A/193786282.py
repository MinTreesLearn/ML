a=int(input())
s=0
for i in range(a):
    b,c=map(int,input().split())
    if b==c:
        s=0
    elif b>c:
        d=b-c
        if d%2==0:
            s=1
        else:
            s=2
    else:
        d=c-b
        if d%2!=0:
            s=1
        else:
            s=2
    print(s)
    s=0
#