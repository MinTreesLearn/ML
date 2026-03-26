for i in range(int(input())):
    a,b,c,n = map(int,input().split())
    x = max(a,b,c)
    rem = 0
    rem+=x-a
    rem+=x-b
    rem+=x-c
    if rem==n and n%3==0:
        print("YES")
    elif((n-rem)%3==0 and (rem>=0 and rem<=n)):
        print("YES")
    else:
        print("NO")
