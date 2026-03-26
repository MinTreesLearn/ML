import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def f(x, y):
    return x * (c2 + 1) + y

q = int(input())
inf = 114514
ans = []
for _ in range(q):
    s = list(input().rstrip())
    t = list(input().rstrip())
    n = len(s)
    m = len(t)
    x = [[-1] for _ in range(26)]
    for i in range(n):
        s[i] -= 97
        x[s[i]].append(i)
    dp0 = [[inf] * n for _ in range(26)]
    for i in range(26):
        xi = x[i]
        for j in range(len(xi) - 1):
            l, r = xi[j], xi[j + 1]
            for k in range(l + 1, r + 1):
                dp0[i][k] = r
    for i in range(m):
        t[i] -= 97
    ans0 = "NO"
    i = 0
    for j in range(n):
        if i == m:
            break
        if s[j] == t[i]:
            i += 1
    if i == m:
        ans0 = "YES"
        ans.append(ans0)
        continue
    for c1 in range(1, m):
        c2 = m - c1
        dp = [inf] * ((c1 + 1) * (c2 + 1))
        dp[0] = 0
        for i in range(c1 + 1):
            for j in range(c2 + 1):
                if dp[f(i, j)] == inf:
                    break
                dpij = dp[f(i, j)]
                if i + 1 < c1 + 1 and dpij < n:
                    u = t[i]
                    if dp0[u][dpij] < inf:
                        dp[f(i + 1, j)] = min(dp[f(i + 1, j)], dp0[u][dpij] + 1)
                if j + 1 < c2 + 1 and dpij < n:
                    u = t[c1 + j]
                    if dp0[u][dpij] < inf:
                        dp[f(i, j + 1)] = min(dp[f(i, j + 1)], dp0[u][dpij] + 1)
        if dp[f(c1, c2)] ^ inf:
            ans0 = "YES"
            break
    ans.append(ans0)
sys.stdout.write("\n".join(ans))