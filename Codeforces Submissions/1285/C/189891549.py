from math import gcd

n = int(input())
x, y = 1e19, 1e19
i = 1
while i*i <= n:
    if n % i == 0 and gcd(i, n//i) == 1:
        if n//i < max(x, y):
            x, y = i, n//i
    i += 1
print(x, y)