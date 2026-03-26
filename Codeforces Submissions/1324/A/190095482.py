import math


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        if n == 1:
            print("YES")
            continue

        ok = True
        for i in range(n - 1):
            ok &= (abs(a[i] - a[i + 1]) & 1) == 0
        if ok:
            print("YES")
        else:
            print("NO")

main()
