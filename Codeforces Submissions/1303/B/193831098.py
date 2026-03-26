t = int(input())
for i in range(t):
    n, g, b = map(int, input().split())
    ng = (n + 1) // 2
    tg = ng // g * (b + g)
    if ng % g == 0:
        tg -= b
    else:
        tg += ng % g
    print(max(n, tg))