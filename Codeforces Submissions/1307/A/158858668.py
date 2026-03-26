def tst(n, d, l):
    for i in range(1, n):
        if d >= i * l[i]:
            d -= l[i] * i
            l[0] += l[i]
        else:
            l[0] += d // i
            break
    print(l[0])
    pass


s = int(input())
for i in range(s):
    n, d = map(int, input().split())
    l = list(map(int, input().split()))
    tst(n, d, l)

