for t in range(int(input())):
    n = int(input())

    a = list(map(int, input().split()))

    if n == 1:
        if a[0] % 2 == 0:
            print(1)
            print(1)
        else:
            print(-1)

    else:
        j = 0

        for i in range(n):
            if a[i] % 2 == 0:
                j = i+1
                break
        if j > 0:
            print(1)
            print(j)
        else:
            print(2)
            print(1, 2)