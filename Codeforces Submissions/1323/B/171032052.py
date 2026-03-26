import sys
input = sys.stdin.readline


def f(x, w, nw):
    if x > nw:
        return 0
    s1 = w[:x].count('1')
    c = 0
    if s1 == x:
        c += 1
    for i in range(nw-x):
        if w[i] == '1':
            s1 -= 1
        if w[i+x] == '1':
            s1 += 1
        if s1 == x:
            c += 1
    return c


def fs(x, y):
    if x == y:
        return f(x, a, n) * f(x, b, m)
    else:
        return f(x, a, n) * f(y, b, m) + f(x, b, m) * f(y, a, n)


n, m, k = map(int, input().split())
a = input()[:-1].replace(' ','')
b = input()[:-1].replace(' ','')

s = {(1, k)}
for i in range(2, int(k**0.5)+1):
    if k % i == 0:
        s.add((i, k//i))

ew = 0
for i, j in s:
    ew += fs(i, j)

print(ew)