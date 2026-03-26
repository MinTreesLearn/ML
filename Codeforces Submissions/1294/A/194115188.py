num=int(input())
for i in range(num):
    a,b,c,n=[int(i) for i in input().split()]
    d=max(a,b,c)
    s=0
    for j in range(1):
        if d!=a:
            s=s+(d-a)
        if d!=b:
            s=s+(d-b)
        if d!=c:
            s=s+(d-c)
    if (n-s)%3==0 and (n-s)>=0:
        print("YES")
    else:
        print("NO")