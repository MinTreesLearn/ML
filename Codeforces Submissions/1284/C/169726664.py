import sys
input = sys.stdin.readline
from collections import deque
n, m = [int(x) for x in input().split()]
ans = 0
fac = [1]
for i in range(n):
    fac.append((fac[-1] * (i + 1)) % m)
for k in range(1, n + 1):
    ans += (n - k + 1) ** 2 * fac[n - k] * fac[k]
    ans = ans % m
print(ans)
