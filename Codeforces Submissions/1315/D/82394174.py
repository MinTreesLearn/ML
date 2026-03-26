import heapq as h
from collections import defaultdict
n=int(input())
a=list(map(int,input().split()))
t=list(map(int,input().split()))
d=defaultdict(list)
for i in range(n):
    d[a[i]].append(t[i])
b=list(d.keys())
c=[]
sm=0
h.heapify(b)
ans=0
while b:
    smallest=h.heappop(b)
    for i in d[smallest]:
        if i==float('inf'):
            continue
        sm += i
        h.heappush(c,-i)
    if c==[]:
        continue
    sm += h.heappop(c)
    ans += sm
    if c==[]:
        continue
    if smallest+1 not in d:
        h.heappush(b,smallest+1)
        d[smallest+1].append(float('inf'))
    d.pop(smallest)
print(ans)