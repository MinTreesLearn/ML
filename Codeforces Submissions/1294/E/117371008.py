import math
n, m = map(int, input().split())
grid = []
for _ in range(n):
    grid.append(list(map(int, input().split())))

ans = 0
for c in range(m):
    cnt = [0 for _ in range(n)]
    for i in range(n):
        grid[i][c] -= (c+1)
        if grid[i][c] % m == 0 and grid[i][c] <= ((n-1)*m):
            cnt[(n+i-grid[i][c]//m)%n] += 1
    mn = n+5
    for i in range(n):
        mn = min(mn, i+n-cnt[i])
    ans += mn

print(ans)
