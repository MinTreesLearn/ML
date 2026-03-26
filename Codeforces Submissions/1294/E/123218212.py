import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 0
for i in range(m):
    cnt = [n + j for j in range(n)]
    j = (i + 1) % m
    for k in range(n):
        if (a[k][i] % m) ^ j or not 1 <= a[k][i] <= n * m:
            continue
        x = i + k * m + 1
        cnt[((x - a[k][i]) % (n * m)) // m] -= 1
    ans += min(cnt)
print(ans)