import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n, m = map(int, input().split())
    l = n - m
    if l <= m + 1:
        ans0 = n * (n + 1) // 2 - l
    else:
        x = l // (m + 1)
        y = l % (m + 1)
        ans0 = n * (n + 1) // 2
        ans0 -= x * (x + 1) // 2 * (m + 1 - y)
        ans0 -= (x + 1) * (x + 2) // 2 * y
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))