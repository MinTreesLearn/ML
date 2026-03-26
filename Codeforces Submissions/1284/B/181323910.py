import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
l = pow(10, 6) + 5
c = [0] * l
u = []
for _ in range(n):
    s = list(map(int, input().split()))[1:]
    f = 0
    for i in range(len(s) - 1):
        if s[i] < s[i + 1]:
            f = 1
            break
    if not f:
        c[s[0]] += 1
        u.append(s[-1])
for i in range(1, l):
    c[i] += c[i - 1]
ng = 0
for i in u:
    ng += c[i]
ans = n * n - ng
print(ans)