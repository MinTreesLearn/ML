import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
inf = pow(10, 9) + 1
for _ in range(t):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    k = min(k, m - 1)
    l = m - k
    c = n - m
    ans0 = 0
    for i in range(k + 1):
        mi = inf
        for j in range(i, i + l):
            mi = min(mi, max(a[j], a[j + c]))
        ans0 = max(ans0, mi)
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))