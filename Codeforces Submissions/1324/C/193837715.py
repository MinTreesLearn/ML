for i in range(int(input())):
    a='R'+input()+'R'
    b=0
    c=0
    for j in range(len(a)):
        if a[j]=='R':
            c=max(c,j-b)
            b=j
    print(c)

