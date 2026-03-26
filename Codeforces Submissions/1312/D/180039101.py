import collections
import math

MOD = 998244353

n, m = list(map(int, input().split(" ")))

N = m + 1

fac = [1] * N
for i in range(1, N):
  fac[i] = (fac[i - 1] * i) % MOD

inv_fac = [1] * N
inv_fac[N - 1] = pow(fac[N - 1], MOD - 2, MOD)
for i in range(N - 2, -1, -1):
  inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % MOD


total = fac[m] * inv_fac[n - 1] * inv_fac[m - n + 1] % MOD

total = (total * pow(2, n - 2, MOD)) % MOD

inv_2 = inv_fac[2]

res = (total * (n - 2) * inv_2) % MOD

print(res)
