a, b = map(int, input().split())
if b % a != 0:
    print(-1)
else:
    n = b // a
    res = 0
    while n != 1 and n % 3 == 0:
        res += 1
        n //=3
    while n != 1 and n % 2 == 0:
        res += 1
        n //=2
    if n == 1:
        print(res)
    else:
        print(-1)