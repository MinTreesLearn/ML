import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

s = list(input().rstrip())
cnt = [0] * 26
x = [0] * (26 * 26)
for i in s:
    for j in range(26):
        x[(i - 97) + j * 26] += cnt[j]
    cnt[i - 97] += 1
ans = max(max(x), max(cnt))
print(ans)