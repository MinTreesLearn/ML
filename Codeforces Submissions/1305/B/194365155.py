import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

s = list(input().rstrip())
n = len(s)
l, r = 0, n - 1
ans = []
while l < r:
    while l < r and s[l] & 1:
        l += 1
    while l < r and not s[r] & 1:
        r -= 1
    if not s[l] & 1 and s[r] & 1:
        ans.append(l + 1)
        ans.append(r + 1)
    else:
        break
    l += 1
    r -= 1
ans.sort()
k, m = 1, len(ans)
if not m:
    k = 0
    print(k)
    exit()
print(k)
print(m)
sys.stdout.write(" ".join(map(str, ans)))