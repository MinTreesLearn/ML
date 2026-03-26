import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
xy = [tuple(map(int, input().split())) for _ in range(n)]
if n % 2:
    ans = "NO"
else:
    ans = "YES"
    for i in range(n):
        u1, u2 = xy[i], xy[(i + 1) % n]
        v1, v2 = xy[(i + n // 2) % n], xy[(i + n // 2 + 1) % n]
        for j in range(2):
            if (u1[j] - u2[j]) ^ (v2[j] - v1[j]):
                ans = "NO"
                break
        if ans == "NO":
            break
print(ans)