def gcd(a, b):
    if a > b:
        a, b = b, a
    if b % a==0:
        return a
    return gcd(b % a, a)

primes = []
for p in range(2, 10**5+1):
    is_prime = True
    for p2 in primes:
        if p2*p2 > p:
            break
        if p % p2==0:
            is_prime = False
            break
    if is_prime:
        primes.append(p)
        
def factor(x):
    d = {}
    for p in primes:
        if p*p > x:
            break
        if x % p==0:
            c = 0
            while x % p==0:
                c+=1
                x = x//p
            d[p] = c
    if x > 1:
        d[x] = 1
    return d

def process(a, m):
    g = gcd(a, m)
    A = a//g
    M = m//g
    d = factor(M)
    answer = 1
    for p in d:
        c = d[p]
        answer = answer*(p-1)*p**(c-1)
    return answer

T = int(input())
for i in range(T):
    a, m = [int(x) for x in input().split()]
    print(process(a, m))