import sys,os,io
from collections import defaultdict
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = [int(i) for i in input().split()]
d = defaultdict(lambda : [])
for i in range (n):
    d[a[i]-i].append(a[i])
ans = 0
for i in d:
    temp = 0
    for j in d[i]:
        temp+=j
    ans = max(ans,temp)
print(ans)