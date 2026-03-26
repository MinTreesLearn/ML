import sys
import math
input = sys.stdin.readline
for __ in range(int(input())):
    a, m = [int(Xx) for Xx in input().split()]
    a, m = a // math.gcd(a, m), m // math.gcd(a, m)
    ans = 1
    i = 2
    M = m
    while i * i <= M:
        if m % i == 0:
            while m % i == 0:
                m = m // i
                ans *= i
            ans = ans // i
            ans = ans * (i - 1)
        i += 1
    if m - 1:
        ans *= (m - 1)
    print(ans)
