import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
s = list(input().rstrip())
c = 0
for i in s:
    c += 1 if i & 1 else -1
if c:
    ans = -1
    print(ans)
    exit()
ans = 0
c = 0
now = 0
f = 0
for i in s:
    c += 1
    now += 1 if not i & 1 else -1
    if now < 0:
        f = 1
    if not now and f:
        ans += c
    if not now:
        c, f = 0, 0
print(ans)