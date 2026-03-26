import math

def __gcd(a,b):
    return (a if b == 0 else __gcd(b,a % b))

def phi(val):
    ret = 1
    for i in range(2,int(math.sqrt(val)) + 1):
        if val % i == 0:
            c = 0
            while val % i == 0:
                val //= i
                c += 1
            ret *= (i - 1)
            for j in range(1,c):
                ret *= i
    if val > 1:
        ret *= (val - 1)
    return ret

for _ in range(int(input())):
    a,m = map(int,input().split())
    g = __gcd(a,m)
    print(phi(m // g))
    
