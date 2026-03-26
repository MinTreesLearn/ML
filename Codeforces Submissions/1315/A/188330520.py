for i in range(int(input())):
    a, b, x, y = map(int, input().split())
    print(max(max(y, b - 1 - y) * a, max(x, a - 1 - x) * b))