for _ in range(int(input())):
    n, d = map(int, input().split())
    if (n + 1)**2 - (4*d) >= 0:
        print('YES')
    else:
        print('NO')



