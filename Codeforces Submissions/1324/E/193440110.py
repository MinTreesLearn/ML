"""
f[i][j], a[0,..,i-1], s[i] % h = j, maxscore
f[i][j] = max(f[i - 1][(j - a[i - 1]) % h], 
              f[i - 1][(j - a[i - 1] + 1) % h]) + (l <= j <= r)
"""
n, h, l, r = list(map(int, input().split()))
a = list(map(int, input().split()))
f = [[float('-inf')] * h for _ in range(n + 1)]
f[0][0] = 0
for i in range(1, n + 1):
    for j in range(h):
        f[i][j] = max(f[i - 1][(j - a[i - 1]) % h], f[i - 1][(j - a[i - 1] + 1) % h]) + int(l <= j <= r)
print(max(f[n]))