for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    p = list(map(int, input().split()))
    p.append(0)
    p = sorted(p)
    p.append(n)
    l = [0 for _ in range(26)]
    d = {}
    for i in range(n):
        d[i] = ord(s[i]) - 97
    i = 0
    k = 1
    while i < len(p) and k <= n:
        if p[i] == k:
            for j in range(p[i-1], p[i]):
                l[d[j]] = l[d[j]] + len(p)-i
            k = k + 1
            i = i + 1
        elif p[i] < k:
            i = i + 1
        else:
            k = k + 1

    print(*l)