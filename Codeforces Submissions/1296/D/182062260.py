from sys import stdin
input = stdin.readline
import math 

n, a, b, k = map(int, input().split())
h = list(map(int, input().split()))

ans = 0; s = []
for e in h:
    if e % (a + b) == 0:
        rem = a + b
    else:
        rem = e % (a + b)

    if a >= rem:
        ans += 1
        continue
    else:
        need = int(math.ceil(rem / a))
        s.append(need - 1)

s.sort()
for e in s:
    if k >= e:
        k -= e
        ans += 1

print(ans)

