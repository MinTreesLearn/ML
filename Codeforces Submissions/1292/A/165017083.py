import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, q = map(int, input().split())
s = [[0] * (n + 2) for _ in range(2)]
now = 0
ans = []
for _ in range(q):
    r, c = map(int, input().split())
    r -= 1
    if not s[r][c]:
        for i in range(c - 1, c + 2):
            if s[r ^ 1][i]:
                now += 1
    else:
        for i in range(c - 1, c + 2):
            if s[r ^ 1][i]:
                now -= 1
    s[r][c] ^= 1
    ans0 = "Yes" if not now else "No"
    ans.append(ans0)
sys.stdout.write("\n".join(ans))