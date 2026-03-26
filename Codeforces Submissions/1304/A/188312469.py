for i in ' ' * int(input()):
    x, y, a, b = map(int, input().split())
    print(-1 if (y - x) % (a + b) else (y - x) // (a + b))  