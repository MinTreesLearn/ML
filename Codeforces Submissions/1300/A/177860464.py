for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = a.count(0)
    if sum(a) + b:
        print(b)
    else:
        print(b + 1)
