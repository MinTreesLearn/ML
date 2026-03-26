import math

t = int(input())

for _ in range(t):
    x = int(input())
    for d in range(1, int(x**0.5) + 1):
        if x % d == 0:
            ab = x * d - d**2
            if ab > 0 and ab % d == 0:
                b = ab // d
                a = x // d - b
                print(a, b)
                break
