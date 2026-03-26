from math import ceil

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    m = max(a)
    if x in a:
        print(1)
    else:
        print(max(2, ceil(x/m)))