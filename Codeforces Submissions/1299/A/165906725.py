import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = list(map(int, input().split()))
pow2 = [1]
for _ in range(30):
    pow2.append(2 * pow2[-1])
for i in reversed(pow2):
    c = 0
    for j in range(n):
        if i & a[j]:
            c += 1
            k = j
        if c >= 2:
            break
    if c == 1:
        break
if c == 1:
    ans = [a[k]] + a[:k] + a[(k + 1):]
else:
    ans = a
sys.stdout.write(" ".join(map(str, ans)))