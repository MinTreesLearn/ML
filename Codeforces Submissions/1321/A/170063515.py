import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
r = list(map(int, input().split()))
b = list(map(int, input().split()))
c1, c2 = 0, 0
for i, j in zip(r, b):
    if not i ^ j:
        continue
    if i:
        c1 += 1
    else:
        c2 += 1
if not c1:
    ans = -1
else:
    ans = 0
    while ans * c1 <= c2:
        ans += 1
print(ans)