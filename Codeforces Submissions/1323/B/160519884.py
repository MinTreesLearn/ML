from collections import defaultdict
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def divisor(i):
    s = []
    for j in range(1, int(i ** (1 / 2)) + 1):
        if i % j == 0:
            s.append(i // j)
            s.append(j)
    return sorted(set(s))

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt1 = defaultdict(lambda : 0)
cnt2 = defaultdict(lambda : 0)
c = 0
for i in a:
    if i:
        c += 1
    elif c:
        cnt1[c] += 1
        c = 0
if c:
    cnt1[c] += 1
    c = 0
for i in b:
    if i:
        c += 1
    elif c:
        cnt2[c] += 1
        c = 0
if c:
    cnt2[c] += 1
x = [(i, cnt1[i]) for i in cnt1]
y = [(i, cnt2[i]) for i in cnt2]
ans = 0
s = divisor(k)
for u in s:
    v = k // u
    if n < u or m < v:
        continue
    c1, c2 = 0, 0
    for i, j in x:
        c1 += max(i - u + 1, 0) * j
    for i, j in y:
        c2 += max(i - v + 1, 0) * j
    ans += c1 * c2
print(ans)