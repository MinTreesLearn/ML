import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, p, k = map(int, input().split())
a = list(map(float, input().split()))
s = [tuple(map(float, input().split())) for _ in range(n)]
b = [(a[i], i) for i in range(n)]
b.sort(reverse = True)
pow2 = [1]
for _ in range(p):
    pow2.append(2 * pow2[-1])
m = pow2[p]
dp0 = [-1.0] * m
dp0[0] = 0.0
dp = [-1.0] * m
c = [bin(i).count("1") for i in range(m)]
u = 0
for ai, i in b:
    u += 1
    si = s[i]
    for j in range(m):
        if dp0[j] < 0:
            continue
        cj = c[j]
        dp0j = dp0[j]
        if u - cj <= k:
            dp[j] = max(dp[j], dp0j + ai)
        else:
            dp[j] = max(dp[j], dp0j)
        for l in range(p):
            pl = pow2[l]
            if j & pl:
                continue
            dp[j ^ pl] = max(dp[j ^ pl], dp0j + si[l])
    dp0, dp = dp, dp0
ans = int(dp0[-1])
print(ans)