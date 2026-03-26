import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    l, r = [], []
    s = set()
    for _ in range(n):
        l0, r0 = map(int, input().split())
        s.add(l0)
        s.add(r0)
        l.append(l0)
        r.append(r0)
    s = list(s)
    s.sort()
    d = dict()
    for i in range(len(s)):
        d[s[i]] = 2 * i
    m = 2 * len(s)
    x = [0] * m
    lr = []
    for l0, r0 in zip(l, r):
        l1, r1 = d[l0], d[r0]
        lr.append((l1, r1))
        x[l1] += 1
        x[r1 + 1] -= 1
    c = 0
    u = []
    s = 0
    for i in range(1, m):
        x[i] += x[i - 1]
        if not x[i]:
            c += 1
            u.append((s, i - 1))
            s = i + 1
    z = [0] * m
    for l, r in u:
        f = 0
        for i in range(l, r + 1):
            if x[i] == 1:
                if f and not x[i + 1] == 1:
                    z[i + 1] = 1
            if not x[i] == 1:
                f = 1
        z[r + 1] = 0
    for i in range(1, m):
        z[i] += z[i - 1]
    ma = 0
    for l, r in lr:
        ma = max(ma, z[r + 1] - z[l])
    ans0 = c + ma if n ^ c else n - 1
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))