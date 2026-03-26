def factors(n):
    return list(
        factor for i in range(1, int(n**0.5) + 1) if n % i == 0
        for factor in (i, n//i)
    )

n,m = map(int, input().split())

if m == n:
    print(0)
elif m % n == 0 and (m % 2 == 0 or m % 3 == 0):    
    steps = m // n
    count = 0
    while steps > 1:
        if steps % 2 == 0:
            count += 1
            steps //= 2
        elif steps % 3 == 0:
            count += 1
            steps //= 3
        else:
            print(-1)
            break
    else:
        print(count)
else:
    print(-1)

