import sys
input = sys.stdin.readline
from heapq import heappop, heappush

for _ in range(int(input())):
    n = int(input())
    s = input()[:-1]
    h = []
    for i in range(n):
        heappush(h, (s[i:] + s[:i][::-1], i+1) if (n-i) & 1 else (s[i:] + s[:i], i+1))
    a, b = heappop(h)
    print(a)
    print(b)