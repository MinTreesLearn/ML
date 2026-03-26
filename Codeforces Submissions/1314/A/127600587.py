from collections import defaultdict
import heapq
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = defaultdict(list)
for i in range(n):
    d[a[i]].append(-b[i])
hq = []
ans = 0
t = 0
l = sorted(d.items()) + [(10 ** 12, [0])]
for i in range(len(l) - 1):
    k, v = l[i]
    t = max(t, k)
    for x in v:
        heapq.heappush(hq, (x, k))
    for i in range(min(len(hq), l[i + 1][0] - l[i][0])):
        x, y = heapq.heappop(hq)
        ans -= (t - y) * x
        t += 1
print(ans)