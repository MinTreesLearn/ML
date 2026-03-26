n = int(input())
for i in range(n):
    a,b,c,n = [int(i) for i in input().split()]
    z = max(a,b,c)
    p = n - (z-a + z-b + z-c)
    if p>=0:
        if p%3==0:
            print("YES")
        else:
            print("NO")
    if p<0:
        print("NO")