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
cols_p = [cols[0]]
for i in range(1, len(cols)): cols_p.append(cols_p[-1] + cols[i])

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
rows_p = [rows[0]]
for i in range(1, len(rows)): rows_p.append(rows_p[-1] + rows[i])


def bsearch(x, arr):
    l, r = 0, len(arr) - 1
    while l <= r:
        m = (l + r) // 2
        if arr[m] >= x:
            l = m + 1
        else:
            r = m - 1
    return l

facs = factors(k)
facs.sort()
ans = 0
for i in range(len(facs)):
    fac1, fac2 = facs[i], k // facs[i]
    j = bsearch(fac1, cols)
    p = 0
    amt = 0
    if j != 0: 
        p = cols_p[j - 1]
        amt = p - j * fac1 + j
    j = bsearch(fac2, rows)
    p = 0
    if j != 0:
        p = rows_p[j - 1]
        amt *= (p - j * fac2 + j)
    else:
        amt = 0
    ans += amt
print(ans)
