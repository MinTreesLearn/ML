import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    ans0 = a[0]
    for i in range(1, n):
        x = min(d // i, a[i])
        ans0 += x
        d -= x * i
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))