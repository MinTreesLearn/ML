n, m = map(int, input().split())
f = [1]
for i in range(1, 250001):
    f.append(f[-1] * i % m)
ans = 0
for i in range(1, n + 1):
    ans += ((((f[i] * f[n-i]) % m)) * (n - i + 1) * (n - i + 1)) % m
    #print(ans)
print(ans % m)
