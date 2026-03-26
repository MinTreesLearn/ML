t = int(input())
for _ in range(t):
    a, b, x, y = (int(i) for i in input().split())
    res = max(x * b, (a - x - 1) * b, y * a, (b - y - 1) * a)
    print(res)
