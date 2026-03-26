import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
a = list(map(int, input().split()))
cnt = [0] * m
for i in a:
    cnt[i % m] += 1
if max(cnt) >= 2:
    ans = 0
    print(ans)
    exit()
ans = 1
for i in range(n):
    ai = a[i]
    for j in range(i + 1, n):
        ans = ans * abs(ai - a[j]) % m
print(ans)