for _ in range(int(input())):
    n, m = list(map(int, input().split(' ')))
    a = sum(list(map(int, input().split(' '))))
    print(a) if a < m else print(m)
