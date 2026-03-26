from functools import lru_cache
n = int(input())
p = list(map(int, input().split()))
c = [i % 2 for i in p].count(1)
if n % 2 == 0:
    t = n // 2 - c
else:
    t = n // 2 - c + 1
@lru_cache(None)
def dfs(i, t, q):
    if t < 0 or t > n - i:
        return float("inf")
    elif i == n:
        return 0 if t == 0 else float("inf")
    if p[i] == 0:
        if q == 0:
            return min(dfs(i + 1, t, 0), dfs(i + 1, t - 1, 1) + 1)
        else:
            return min(dfs(i + 1, t - 1, 1), dfs(i + 1, t, 0) + 1)
    else:
        return abs(q - p[i] % 2) + dfs(i + 1, t, p[i] % 2)
if p[0] == 0:
    print(min(dfs(1, t - 1, 1), dfs(1, t, 0)))
else:
    print(dfs(1, t, p[0] % 2))