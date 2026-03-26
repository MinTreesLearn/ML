import sys
input = sys.stdin.readline

n, a, b, k = map(int, input().split())
w = list(map(int, input().split()))

d = []
x = a + b
for i in w:
    if i % x == 0:
        i = x
    else:
        i %= x
    d.append(i)
d.sort()
c = 0
x = 0
for i in d:
    x = i//a - (i%a==0)
    if k >= x:
        k -= x
        c += 1
    else:
        break
print(c)
