t=int(input())
for _ in range(t):
    a,b,c,d=map(int,input().split())
    if (a+b+c+d)%3==0 and (a+b+c+d)/3>=a and (a+b+c+d)/3>=b and (a+b+c+d)/3>=c:
        print('YES')
    else:
        print('NO')