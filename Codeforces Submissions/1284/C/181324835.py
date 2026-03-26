import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
l = n + 5
fact = [1] * (l + 1)
for i in range(1, l + 1):
    fact[i] = i * fact[i - 1] % m
ans = 0
for i in range(1, n + 1):
    c = n - i + 1
    ans += pow(c, 2, m) * fact[i] % m * fact[n - i] % m
    ans %= m
print(ans)