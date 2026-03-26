from collections import defaultdict
import heapq
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
d = defaultdict(lambda : [])
for i, j in zip(a, t):
    d[i].append(j)
x = list(d.keys())
x.sort()
i = 0
ans = 0
s = 0
h = []
for i in range(len(x)):
    u = x[i]
    while d[u]:
        v = d[u].pop()
        s += v
        heapq.heappush(h, -v)
    while h:
        if u in d:
            while d[u]:
                v = d[u].pop()
                s += v
                heapq.heappush(h, -v)
        s += heapq.heappop(h)
        ans += s
        u += 1
print(ans)