from sys import stdin
from math import inf

n = int(stdin.readline())
verts = list()
for i in range(n):
    x, y = map(int, stdin.readline().split())
    verts.append((x, y))
cur = -1
if n%2 == 0:
    flg = True
    for i in range(n//2):
        x, y = verts[i]
        xx, yy = verts[n//2+i]
        ths = (xx+x, yy+y)
        if cur == -1: cur = ths
        if ths != cur: flg = False
    if flg: print("YES")
    else: print("NO")
else:
    print("NO")