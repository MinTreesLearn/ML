import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

s = [0] + list(input().rstrip())
q = int(input())
c0 = [0] * 26
c = [list(c0)]
for i in s[1:]:
    c0[i - 97] += 1
    c.append(list(c0))
ans = []
for _ in range(q):
    l, r = map(int, input().split())
    if s[l] ^ s[r] or l == r:
        ans0 = "Yes"
    else:
        cnt = 0
        for i, j in zip(c[l - 1], c[r]):
            cnt += min(i ^ j, 1)
        ans0 = "Yes" if cnt >= 3 else "No"
    ans.append(ans0)
sys.stdout.write("\n".join(ans))