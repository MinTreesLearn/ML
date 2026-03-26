for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == b:
        print(0)
    elif a > b:        
        print(1 if (a - b) % 2 == 0 else 2)
    else:
        print(2 if (a - b) % 2 == 0 else 1)