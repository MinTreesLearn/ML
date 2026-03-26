for _ in range(int(input())):
    a, b, p = map(int, input().split())
    s = input()
    if s[0] == 'A':
        j = 0
        c = 1*a
    else:
        j = 1
        c = 1*b

    for i in range(1, len(s)-1):
        if s[i] == 'A' and j == 1:
            c = c + a
            j = 0
        elif s[i] == 'B' and j == 0:
            c = c + b
            j = 1

    i = 1
    if s[0] == 'A':
        j = 0
    else:
        j = 1
    while c > p and i < len(s):
        if s[i] == 'A' and j == 1:
            c = c - b
            j = 0
        elif s[i] == 'B' and j == 0:
            c = c - a
            j = 1
        i = i + 1

    print(i)



