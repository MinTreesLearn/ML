for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    i = n
    j = -1
    for k in range(n):
        if a[k] < k:
            break
        j = k
    for k in range(n-1, -1, -1):
        if a[k] < (n-k-1):
            break
        i = k
    if j >= i:
        print('YES')
    else:
        print('NO')