import sys
input = sys.stdin.readline

n, m = map(int, input().split())
d = [1]
c = 0
for i in range(1, n+1):
    d.append(d[-1]*i%m)
for i in range(1, n+1):
    c += (n-i+1)*d[n-i+1]*d[i]%m
    c %=m
print(c)