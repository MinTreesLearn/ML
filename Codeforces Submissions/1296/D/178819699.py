from math import ceil


n, a, b, k = map(int, input().split())
m = a + b
h = list(map(lambda x: int(x) % m + (m if int(x) % m == 0 else 0), input().split()))
h.sort()
cnt = 0
while cnt < n and h[cnt] <= a:cnt += 1
del h[:cnt]
s = 0
for hp in h:
    cnt += 1
    s += ceil(hp / a) - 1
    if k < s:
        cnt -= 1
        break
print(cnt)
