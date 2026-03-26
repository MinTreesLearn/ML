for _ in range(int(input())):
    n = input()
    s = input()
    a = 0
    for i in s:
        a += int(i)
    m = int(s)
    flag = True
    while True:
        if a % 2 == 0 and int(s) % 2 != 0:
            print(s)
            flag = False
            break
        a -= int(s[-1])
        s = s[0:-1]
        if len(s) == 0:
            break
    if flag:
        print(-1)