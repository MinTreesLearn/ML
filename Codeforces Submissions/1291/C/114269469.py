from sys import stdin

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    l = list(map(int, input().split()))
    k = min(k, m - 1)
    b = [max(l[i], l[n + i - m]) for i in range(m)]
    x = max(min(b[i:i + m - k]) for i in range(k + 1))
    print(x)
