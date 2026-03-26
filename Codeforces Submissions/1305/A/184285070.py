t = int(input())
for _ in range(t):
    n = int(input())
    a = (int(i) for i in input().split())
    b = (int(i) for i in input().split())
    res = sorted(a)
    print(*res)
    res = sorted(b)
    print(*res)
