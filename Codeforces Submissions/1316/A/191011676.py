for t in range(int(input())):
    n , m = map(int, input().split())

    a = list(map(int, input().split()))
    s = sum (a)

    if s > m:
        print(m)
    else:
        print(s)
