from sys import stdin
input = stdin.readline
from collections import defaultdict

n, m = map(int, input().split())
a = list(map(int, input().split()))

if len(a) > m:
    #by pigeonhole guaranteed k st. there exists i, j st a[i] % m == a[j] % m == k=> product will be 0
    print(0)
else:
    ans = 1
    for i in range(n):
        for j in range(i + 1, n):
            ans *= abs(a[i] - a[j])
            if ans >= m: ans %= m

    print(ans)