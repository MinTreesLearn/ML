import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def sparse_table(a):
    table = []
    s0, l = a, 1
    table.append(s0)
    while 2 * l <= len(a):
        s = [max(s0[i], s0[i + l]) for i in range(len(s0) - l)]
        table.append(list(s))
        s0 = s
        l *= 2
    return table

def get_max(l, r, table):
    d = len(bin(r - l + 1)) - 3
    ans = max(table[d][l], table[d][r - pow2[d] + 1])
    return ans

n, m, k = map(int, input().split())
s = []
for _ in range(n):
    s0 = list(map(int, input().split()))
    u = [0]
    for i in s0:
        u.append(u[-1] + i)
    s.append(u)
s.append([0] * (m + 1))
l = m - k + 1
dp0 = [0] * l
s0, s1 = s[0], s[1]
for i in range(l):
    dp0[i] = s0[i + k] + s1[i + k] - s0[i] - s1[i]
s0 = s[1]
pow2 = [1]
for _ in range(20):
    pow2.append(2 * pow2[-1])
for i in range(1, n):
    s1 = s[i + 1]
    dp = [0] * l
    table = sparse_table(dp0)
    for j in range(l):
        c = s0[j + k] + s1[j + k] - s0[j] - s1[j]
        dpj = 0
        for u in range(max(0, j - k + 1), min(l, j + k)):
            x, y = max(j, u), min(j, u) + k
            dpj = max(dpj, dp0[u] + c - s0[y] + s0[x])
        if j - k >= 0:
            dpj = max(dpj, get_max(0, j - k, table) + c)
        if j + k <= l - 1:
            dpj = max(dpj, get_max(j + k, l - 1, table) + c)
        dp[j] = dpj
    dp0 = dp
    s0 = s1
ans = max(dp0)
print(ans)