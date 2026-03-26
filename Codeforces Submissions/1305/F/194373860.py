import random
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def the_sieve_of_eratosthenes(n):
    s = [1] * (n + 1)
    x = []
    for i in range(2, n + 1):
        if s[i]:
            x.append(i)
            for j in range(i, n + 1, i):
                s[j] = 0
    return x

n = int(input())
a = list(map(int, input().split()))
x = the_sieve_of_eratosthenes(pow(10, 6))
s = set(x[:20])
for _ in range(30):
    v = a[random.randint(0, n - 1)]
    for u0 in range(max(v - 2, 1), v + 3):
        u = u0
        for i in x:
            if u % i:
                continue
            s.add(i)
            while not u % i:
                u //= i
        if u ^ 1:
            s.add(u)
ans = n
for i in s:
    c = 0
    for j in a:
        c += min(j % i, -j % i) if j >= i else -j % i
    ans = min(ans, c)
print(ans)