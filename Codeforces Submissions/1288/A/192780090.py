import math

n = int(input())

for _ in range(n):
    n, d = map(int, input().split())

    bot = int(math.sqrt(d)) + 10
    x = 0
    while x < bot:
        if x + (d + x) // (x + 1) <= n:
            break
        x += 1

    if x < bot:
        print("YES")
    else:
        print("NO")