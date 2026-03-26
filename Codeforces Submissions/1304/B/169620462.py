import collections
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
data = [input().rstrip() for _ in range(n)]
sdata = set(data)

f = []
s = []
spi = -1
sp = ''

for i in range(n):
    tmp = False
    for j in range(i + 1, n):
        if data[i] == data[j][::-1]:
            tmp = True
            f.append(data[i])
            s.append(data[j])
    if spi == -1 and not tmp and data[i] == data[i][::-1]:
        spi = i
        sp = data[i]

print(len(f) * 2 * m + (m if spi != -1 else 0))
print(''.join(f) + sp + ''.join(s[::-1]))