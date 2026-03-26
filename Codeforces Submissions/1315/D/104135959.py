from sys import stdin
from heapq import *

rint = lambda: int(stdin.readline())
rints = lambda: [int(x) for x in stdin.readline().split()]

ans, n, su, ix, que = 0, rint(), 0, 0, []
a = sorted(map(lambda x, y: (x, y), rints(), rints()))
lst = a[ix][0]

while ix < n:
    while que and a[ix][0] - lst > 1:
        su += heappop(que)
        lst += 1
        ans += su

    lst = a[ix][0]
    while ix < n and a[ix][0] == lst:
        heappush(que, -a[ix][1])
        su += a[ix][1]
        ix += 1

    su += heappop(que)
    ans += su

while que:
    su += heappop(que)
    ans += su
print(ans)
