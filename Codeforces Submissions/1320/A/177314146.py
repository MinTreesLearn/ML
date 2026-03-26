import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
b = list(map(int, input().split()))
l = pow(10, 6)
s = [0] * l
for i in range(n):
    s[b[i] - i] += b[i]
ans = max(s)
print(ans)