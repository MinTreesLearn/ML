import sys
input = sys.stdin.readline
from collections import *
from heapq import *

n = int(input())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
d = defaultdict(list)

for i in range(n):
    d[a[i]].append(t[i])

ks = list(d.keys())
ks.sort()
prev = ks[0]
ans = 0
s = 0
pq = []

for a in ks:
    for _ in range(a-prev-1):
        if len(pq)==0:
            break
        
        ans += s
        s -= -heappop(pq)
        
    ans += s
        
    for t in d[a]:
        heappush(pq, -t)
        s += t
    
    s -= -heappop(pq)
    prev = a
    
while len(pq):
    ans += s
    s -= -heappop(pq)

print(ans)