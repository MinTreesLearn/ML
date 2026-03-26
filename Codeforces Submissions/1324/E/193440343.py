"""
f[i][j], a[0,..,i-1], s[i] % h = j, maxscore
f[i][j] = max(f[i - 1][(j - a[i - 1]) % h], 
              f[i - 1][(j - a[i - 1] + 1) % h]) + (l <= j <= r)
"""
inf = float('inf')
n, h, l, r = list(map(int, input().split()))
a = list(map(int, input().split()))
f = [-inf] * h
f[0] = 0
for i in range(1, n + 1):
    g = [0] * h
    for j in range(h):
        g[j] = max(f[(j - a[i - 1]) % h], f[(j - a[i - 1] + 1) % h]) + int(l <= j <= r)
    f = g
print(max(f))