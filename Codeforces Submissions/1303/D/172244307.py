import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

import math

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    C = [0]*61
    s = 0
    for a in A:
        C[int(math.log2(a))] += 1
        s += a
    if s < n:
        print(-1)
        continue

    i = 0
    res = 0
    while i < 60:
        if (n>>i)&1:
            if C[i] > 0:
                C[i] -= 1
            else:
                while i < 60 and C[i] == 0:
                    i += 1
                    res += 1
                C[i] -= 1
                continue
        C[i+1] += C[i]//2
        i += 1
    print(res)
