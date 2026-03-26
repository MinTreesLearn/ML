for _ in range(int(input())):
    a = input()
    b = input()
    c = input()
    s = 'YES'
    for i in range(len(a)):
        if not(c[i] == a[i] or c[i] == b[i]):
            s = 'NO'
            break
    print(s)