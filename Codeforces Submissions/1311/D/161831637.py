import sys
input=sys.stdin.readline
for _ in range(int(input())):
    a,b,c=map(int,input().split())#1w
    move=10**6
    ans=[0,0,0]
    for x in range(1,c+1):
        for y in range(x,c+101,x):
            cost=abs(a-x)+abs(b-y)
            if c%y<y-(c%y):
                z=c-c%y
                cost+=c%y
            else:
                z=c+(y-c%y)
                cost+=y-c%y
            if move>cost:
                move=cost
                ans=[x,y,z]
    print(move)
    print(*ans)

