for t in range(int(input())):
    n, m = map(int, input().split())

    a = list(map(int, input().split()))

    p = list(map(int, input().split()))

    while True:
        state = False
        for i in p:
            if a[i - 1] > a[i]:
                state = True
                a[i - 1], a[i] = a[i], a[i - 1]

        if not state:
            break
            
    if a == sorted(a):
        print('YES')
    else:
        print('NO')
