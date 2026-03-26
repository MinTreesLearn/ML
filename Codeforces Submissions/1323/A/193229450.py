for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    for i in range(n):
        if arr[i] % 2 == 0:
            print(1)
            print(i + 1)
            break
    else:
        if n == 1:
            print(-1)
        else:
            print(2)
            print(1, 2)
