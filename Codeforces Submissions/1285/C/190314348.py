import math

n = int(input())
ans = 1

for i in range(1, int(math.sqrt(n))+1):
    if n % i == 0 and math.gcd(i, n // i) == 1:
        ans = i

print(ans, n // ans)