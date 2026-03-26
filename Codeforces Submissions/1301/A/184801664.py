for _ in range(int(input())):
    a = input()
    b = input()
    c = input()

    for i in range(len(a)):
        if c[i] not in (a[i], b[i]):
            print("NO")
            break
    else:
        print("YES")