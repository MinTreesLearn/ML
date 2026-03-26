t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    if n == 1 or a[0] == m:
        print(a[0])
        continue
    summary = sum(a[1:])
    smth = summary / m
    if smth >= 1:
        a[0] = m
    else:
        a[0] += summary % m
        if a[0] > m:
            a[0] = m
    print(a[0])
