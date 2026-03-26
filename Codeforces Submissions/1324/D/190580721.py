n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = sorted([a[i] - b[i] for i in range(n)])

ans = 0
l = 0
r = n - 1

while l < r:
    if c[l] + c[r] > 0:
        ans += r - l
        r -= 1
    else:
        l += 1

print(ans)


