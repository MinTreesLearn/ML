for t in range(int(input())):
    n, d = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    i = 1
    while(d > 0 and i < n):
        m = min(d, a[i]*i)//i
        d -= m*i
        a[0] += m
        i += 1
    print(a[0])
                     
