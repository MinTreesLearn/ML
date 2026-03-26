import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

from collections import defaultdict

n, m = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]

pair = []
for i in range((1<<m)-1):
    for j in range(i+1, 1<<m):
        if (i|j) == (1<<m)-1:
            pair.append((i, j))

def is_ok(x):
    C = defaultdict(lambda:-1)
    for i in range(n):
        k = 0
        for j in range(m):
            if A[i][j] >= x:
                k |= 1<<j
            C[k] = i
    if C[(1<<m)-1] != -1:
        return (C[(1<<m)-1],C[(1<<m)-1])
    for k, l in pair:
        if C[k] != -1 and C[l] != -1:
            return (C[k], C[l])
    return (-1, -1)

ok = 0
ng = 10**9+50
while ok+1 < ng:
    mid = (ok+ng)//2
    if is_ok(mid) != (-1, -1):
        ok = mid
    else:
        ng = mid
i, j = is_ok(ok)
print(i+1, j+1)
