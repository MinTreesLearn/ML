import math


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = -1
        for i in range(2, int(n ** 0.34 + 5)):
            if n % i == 0:
                a = i
                break

        if a == -1:
            print("NO")
            continue

        n //= a
        b = -1
        for i in range(2, int(n ** 0.5 + 5)):
            if i == a: continue
            if n % i == 0:
                b = i
                break

        if b == -1 or n // b in [1, a, b]:
            print("NO")
            continue

        print("YES")
        print(a, b, n // b)



main()
