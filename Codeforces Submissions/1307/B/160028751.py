for _ in range(int(input())):
    n, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    f = max(a)
    if f < x:
        print((x + f - 1) // f)
    elif x in a:
        print(1)
    else:
        print(2)
