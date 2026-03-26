def solve():
    for _ in range(int(input())):
        a, b, x, y = map(int, input().split())
        num1 = x * b
        num2 = y * a
        num3 = (a - x - 1) * b
        num4 = (b - y - 1) * a
        print(max(num1, num2, num3, num4))

solve()