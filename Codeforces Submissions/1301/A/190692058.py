for n in range(int(input())):
    a = input()
    b = input()
    c = input()
    flag = True
    for i in range(len(a)):
        if a[i] != c[i] and c[i] != b[i]:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")
