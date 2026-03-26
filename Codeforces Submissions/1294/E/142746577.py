import sys
import io, os
input = sys.stdin.buffer.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
#B = [[0]*m for i in range(n)]
#for i in range(n):
    #for j in range(m):
        #B[i][j] = i*m+j
#print(B)
for i in range(n):
    for j in range(m):
        A[i][j] -= 1
ans = 0
from collections import Counter
for j in range(m):
    C = Counter()
    for i in range(n):
        if A[i][j]%m != j:
            continue
        else:
            q, r = divmod(A[i][j], m)
            if 0 <= q < n:
                if q <= i:
                    C[i-q] += 1
                else:
                    C[n+i-q] += 1
    temp = n
    for k, v in C.items():
        temp = min(temp, k+n-v)
    ans += temp
print(ans)
