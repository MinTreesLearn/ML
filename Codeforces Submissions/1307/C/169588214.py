import sys
input = sys.stdin.readline
from itertools import combinations

s = input()[:-1]
d = []
x = 0
for i in range(97, 123):
    d.append(chr(i))
for a, b in combinations(d, 2):
    c0, c1 = 0, 0
    x0, x1 = 0, 0
    for i in s:
        if i == a:
            c0 += 1
            x0 += c1
        elif i == b:
            c1 += 1
            x1 += c0
    x = max(x, c0*(c0-1)//2, c1*(c1-1)//2, x0, x1, c0, c1)

print(x)