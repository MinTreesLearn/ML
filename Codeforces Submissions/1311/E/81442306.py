for _ in range(int(input())):
    n, d = map(int, input().split())
    ld, rd = 0, n * (n - 1) // 2
    tn = n
    cd = 0
    mvl = 1
    while tn:
        vl = min(tn, mvl)
        ld += cd * vl
        cd += 1
        tn -= vl
        mvl *= 2
    if not (ld <= d <= rd):
        print('NO')
        continue
    parent = [i-1 for i in range(n)]
    bad = [False] * n
    deep = [i for i in range(n)]
    child = [1] * n
    child[-1] = 0
    cur = rd
    while cur > d:
        v = None
        for i in range(n):
            if not bad[i] and not child[i] and (v is None or deep[i] < deep[v]):
                v = i
        p = None
        for i in range(n):
            if child[i] < 2 and deep[i] < deep[v] - 1 and (p is None or deep[i] > deep[p]):
                p = i
        if p is None:
            bad[v] = True
        else:
            child[parent[v]] -= 1
            deep[v] -= 1
            child[p] += 1
            parent[v] = p
            cur -= 1
    print('YES')
    print(*map(lambda x: x + 1, parent[1:]))
