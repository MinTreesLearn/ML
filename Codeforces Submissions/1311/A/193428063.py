for _ in range(int(input())):
    a, b = tuple(int(i) for i in input().split())
    
    if a == b:
        print(0)
    elif a > b:
        print((1, 2)[(a - b) & 1])
    else:
        print((2, 1)[(b - a ) & 1])