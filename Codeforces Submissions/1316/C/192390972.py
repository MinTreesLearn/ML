import sys
import random
input = sys.stdin.readline
n, m, p = [int(xx) for xx in input().split()]
a = [int(xx) for xx in input().split()]
b = [int(Xx) for Xx in input().split()]
for i in range(n):
    a[i] %= p
for i in range(m):
    b[i] %= p
pr1 = [0]
pr2 = [0]
for i in range(n):
    pr1.append(pr1[-1] + a[i])
for i in range(m):
    pr2.append(pr2[-1] + b[i])
for i in range(n):
    if pr1[i]:
        break
for j in range(m):
    if pr2[j]:
        break
for x in range(max(0, i + j - 2), 101010101101010101):
    ans = 0
    for i in range(min(x + 1, n)):
        if x - i < m:
            ans += a[i] * b[x - i]
    if ans % p:
        print(x)
        quit()
