t = int(input())
for i in range(t):
    n, d = map(int, input().split())
    *a, = map(int, input().split())
    cnt = 1
    while len(a) > 1 and d > 0 and d >= cnt:
        m = min(d // cnt, a[1])
        a[0] += m
        d -= m * cnt
        del a[1]
        cnt += 1
    print(a[0])
