import math
import sys
input = sys.stdin.readline

def prime_factorize(n):
    ans = []
    for i in range(2, int(n ** (1 / 2)) + 1):
        while True:
            if n % i:
                break
            ans.append(i)
            n //= i
        if n == 1:
            break
    if not n == 1:
        ans.append(n)
    return ans

def euler_func(n):
    p = set(prime_factorize(n))
    x = n
    for i in p:
        x *= (i - 1)
        x //= i
    return x

t = int(input())
ans = []
for _ in range(t):
    a, m = map(int, input().split())
    g = math.gcd(a, m)
    m //= g
    a //= g
    ans0 = euler_func(m)
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))