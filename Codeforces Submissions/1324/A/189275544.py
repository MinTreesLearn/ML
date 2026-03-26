q = int(input())
while q:
    w = int(input())
    a = list(map(int, input().split()))
    t = a[0]%2
    for o in a:
        if(o%2!=t):
            t=2
            break
    if(t==2):
        print("NO")
    else:
        print("YES")
    q-=1  