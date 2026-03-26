t=int(input())
for i in range(t):
    a,b,c,n=map(int,input().strip().split())
    sum=a+b+c+n
    maxt=max(a,(max(b,c)))
    if sum%3==0 and sum/3>=maxt:
        print("YES")
    else:
        print("NO")

