from heapq import heappop, heappush, heapify
from collections import defaultdict

# iはai種類
n = int(input())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
heap = []
d = defaultdict(list)
for i in range(n):
    d[a[i]].append(t[i])
used = set()
heap2 = list(set(a))
heapify(heap2)

ans = 0
s = 0
while heap2:
    cur = heappop(heap2)
    if cur in used:
        continue
    used.add(cur)
    for ti in d[cur]:
        heappush(heap, -ti)
        s += ti
    if heap:
        ti = -heappop(heap)
        s -= ti
        ans += s
        heappush(heap2, cur+1)
print(ans)
