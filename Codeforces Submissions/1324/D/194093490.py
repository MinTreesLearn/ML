from bisect import bisect_left


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = [a[i] - b[i] for i in range(n)]
c.sort()

ans = 0
for i in range(n):
    if c[i] <= 0:
        continue
    pos = bisect_left(c, -c[i]+1)
    ans += i - pos

print(ans)
