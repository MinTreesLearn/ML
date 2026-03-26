# LUOGU_RID: 101845080
for _ in range(int(input())):
    n, s, k = map(int, input().split())
    a = list(map(int, input().split()))
    c = [1] + [(s - i < 1) + (s + i > n) for i in range(1, k)]
    for x in a:
        if abs(x - s) < k:
            c[abs(x - s)] += 1
    p = 0
    while p < k and c[p] == 2:
        p += 1
    print(p)