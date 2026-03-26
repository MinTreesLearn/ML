import sys;input=sys.stdin.readline
for i in range(int(input())):
    a,b,c=map(int,input().split())
    ans=int(1e19)
    el=[0,0,0]
    for i in range(1,10001):
        for j in range(i,20001,i):
            if ans>abs(a-i)+abs(b-j)+j-c%j:
                el=[i,j,c+j-c%j]
                ans=abs(a-i)+abs(b-j)+j-c%j
            if ans>abs(a-i)+abs(b-j)+c%j and c>=j:
                el=[i,j,c-c%j]
                ans=abs(a-i)+abs(b-j)+c%j
    print(ans)
    print(*el)
    
