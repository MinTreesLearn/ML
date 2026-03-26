import sys
input = sys.stdin.readline
from collections import Counter

n = int(input())
w = list(map(int, input().split()))
d = [w[i]-i for i in range(n)]
c = Counter()
for i in range(n):
    c[d[i]] += w[i]
print(max(c.values()))
