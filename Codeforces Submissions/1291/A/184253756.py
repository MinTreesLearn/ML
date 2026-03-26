for _ in range(int(input())):
    n= int(input())
    s= input()

    odd= 0
    for i in range(n):
        if int(s[i])%2 == 1:
            odd += 1

    if odd <= 1:
        print(-1)
    else:
        even= str()
        for k in range(n):
            if int(s[k])%2 == 1:
                even += s[k]
            if len(even) == 2:
                print(even)
                break
        else:
            print(-1)