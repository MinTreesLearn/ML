import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
x = pow(10, 8)
ans = []
for i in range(1, n + 1):
    c = len(ans) // 2
    if not m:
        ans.append(x + 3 * i * n)
    elif m >= c:
        m -= c
        ans.append(i)
    else:
        u = 2 * m
        m = 0
        ans.append(ans[-1] + ans[-u])
if m:
    ans = [-1]
sys.stdout.write(" ".join(map(str, ans)))