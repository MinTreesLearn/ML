for i in range(int(input())):

    a = [int(_) for _ in input().split()]
    b = [int(_) for _ in input().split()]

    if a[1] <= sum(b):
        print(a[1])

    else:
        print(sum(b))
