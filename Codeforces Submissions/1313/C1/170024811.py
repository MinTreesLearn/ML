import sys
input = sys.stdin.readline

n = int(input())
w = list(map(int, input().split()))
x = 0
q = []
for i in range(n):
    a = b = w[i]
    d = [a]
    e = []
    for l in range(i+1, n):
        if w[l] < a:
            a = w[l]
        d.append(a)
    for l in range(i-1, -1, -1):
        if w[l] < b:
            b = w[l]
        e.append(b)
    c = sum(d) + sum(e)
    if c > x:
        x = c
        q = e[::-1] + d
print(' '.join(map(str, q)))