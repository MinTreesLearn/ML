t = int(input())
for _ in range(t):
    n, d = (int(i) for i in input().split())
    a = (int(i) for i in input().split())
    res = next(a)
    for i, e in enumerate(a):
        res += min(d, (i + 1) * e) // (i + 1)
        d -= (i + 1) * e
        if d <= 0:
            break
    print(res)
