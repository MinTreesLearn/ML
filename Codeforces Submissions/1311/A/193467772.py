for i in range(int(input())):
    a,b = map(int, input().split())
    if a>b:
        diff = a - b
        if diff%2 == 0:
            print(1)
        else:
            print(2)
    elif a<b:
        diff = b-a
        if diff%2!=0:
            print(1)
        else:
            print(2)
    else:
        print(0)