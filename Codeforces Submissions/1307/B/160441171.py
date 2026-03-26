for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    if x in a:
        print(1)
    else:
        m = max(a)
        print(max(2, (x + m - 1) // m))
