for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(' ')))
    x, y, z = -1, -1, -1
    for i in range(n):
        if a[i] % 2 == 0:
            z = i + 1
            break
        else:
            if x == -1:
                x = i + 1
            else:
                y = i + 1
                break
    if z != -1:
        print(1)
        print(z)
    elif y != -1:
        print(2)
        print(x, y)
    else:
        print(-1)
