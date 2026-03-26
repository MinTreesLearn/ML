import sys
input = sys.stdin.readline
import bisect

n = int(input())
a, b = [], []

for i in range(n):
    w = list(map(int, input().split()))[1:]
    if sorted(w) == w[::-1]:
        a.append(w[0])
        b.append(w[-1])

a.sort()
print(n**2 - sum(bisect.bisect_right(a, i) for i in b))