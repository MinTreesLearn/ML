for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    found = False
    for j in range(n):
        if a[j] % 2 == 0:
            found = True
            print(1)
            print(j + 1)
            break
    if not found:
        if n == 1:
            print(-1)
        else:
            print(2)
            print(1, 2)