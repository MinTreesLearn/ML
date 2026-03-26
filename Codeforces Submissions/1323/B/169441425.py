import sys
import math
import collections
from heapq import heappush, heappop
from functools import reduce
input = sys.stdin.readline
 
ints = lambda: list(map(int, input().split()))

def factors(n):    
    return list(set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))

n, m, k = ints()
a = ints()
b = ints()

cols = []
cnt = 0
for i in range(m):
    if b[i] == 1:
        cnt += 1
    else:
        cols.append(cnt)
        cnt = 0
cols.append(cnt)
cols.sort(reverse=True)

rows = []
cnt = 0
for i in range(n):
    if a[i] == 1:
        cnt += 1
    else:
        rows.append(cnt)
        cnt = 0
rows.append(cnt)
rows.sort(reverse=True)

facs = factors(k)
ans = 0
for fac in facs:
    if fac <= n and k // fac <= m:
        amt1 = 0
        amt2 = 0
        for i in range(len(cols)):
            if cols[i] >= k // fac:
                amt1 += cols[i] - k // fac + 1
        for i in range(len(rows)):
            if rows[i] >= fac:
                amt2 += rows[i] - fac + 1
        if amt1 > 0 and amt2 > 0: ans += amt1 * amt2
print(ans)

