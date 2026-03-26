m, n = map(int, input().split())

if n%m != 0:
    print(-1)
else:
    d = n//m
    p = 0
    while d%2 == 0 or d%3 == 0:
        if d%2 == 0:
            p += 1
            d = d//2
        if d%3 == 0:
            p += 1
            d = d//3
    if d == 1:
        print(p)
    else:
        print(-1)
