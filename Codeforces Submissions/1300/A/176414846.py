t = int(input())
for _ in range(t):
    n, a = int(input()), [int(i) for i in input().split()]
    z, s = sum(i == 0 for i in a), sum(a)
    res = z + (z + s == 0)
    print(res)
