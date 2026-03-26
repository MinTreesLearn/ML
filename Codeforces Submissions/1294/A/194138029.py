for _ in range(int(input())):
    a,b,c,n=map(int,input().split())
    mx=max(a,b)
    mx=max(mx,c)
    n-=(3*mx)-(a+b+c)
    if n<0:
        print('NO')
        continue
    elif n%3==0:
        print("YES")
    else:
        print("NO")