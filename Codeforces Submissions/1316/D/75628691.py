import itertools as it
from collections import deque

n = int(input())
bd = [[] for _ in range(n)]
for i in range(n):
    lt = list(map(int, input().split()))
    for j in range(n):
        bd[i].append((lt[j*2]-1, lt[j*2+1]-1))

def rpath(tr, tc, r, c):
    q = deque([(r, c)])
    while q:
        i, j = q.popleft()
        edge = [(i-1,j,'D'), (i+1,j,'U'), (i,j-1,'R'), (i,j+1,'L')]
        for a, b, d in edge:
            if a < 0 or a >= n or b < 0 or b >= n: continue
            if bd[a][b] != (tr,tc) or res[a][b]: continue
            res[a][b] = d
            q.append((a, b))

ok = 1
res = [[None]*n for _ in range(n)]
for i, j in it.product(range(n), range(n)):
    if bd[i][j] == (i,j):
        res[i][j] = 'X'
        rpath(i, j, i, j)
    elif bd[i][j] == (-2,-2):
        edge = [(i-1,j,'U','D'), (i+1,j,'D','U'), (i,j-1,'L','R'), (i,j+1,'R','L')]
        for a, b, cur, next in edge:
            if a < 0 or a >= n or b < 0 or b >= n: continue
            if bd[a][b] != (-2,-2): continue
            res[i][j], res[a][b] = cur, next
            break
        else:
            ok = 0; break

if not all(res[i][j] for i, j in it.product(range(n), range(n))):
    ok = 0

print("VALID" if ok else "INVALID")
if ok: print('\n'.join([''.join(u) for u in res]))
