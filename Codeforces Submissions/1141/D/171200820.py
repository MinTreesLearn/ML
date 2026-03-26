import sys
input = sys.stdin.readline
from collections import defaultdict

n = int(input())
l = set()
r = defaultdict(list)
a = input()[:-1]
b = input()[:-1]
for i in range(n):
    r[b[i]].append(i)
    if a[i] == '?':
        l.add(i)

ew = []
x = [0]*n
for i in range(n):
    if a[i] != '?':
        if a[i] in r:
            q = r[a[i]].pop()
            ew.append((i+1, q+1))
            x[q] = 1
            if not r[a[i]]:
                del r[a[i]]
        else:
            if '?' in r:
                q = r['?'].pop()
                ew.append((i + 1, q + 1))
                x[q] = 1
                if not r['?']:
                    del r['?']
j = 0
for i in l:
    while x[j] == 1:
        j += 1
    ew.append((i+1, j+1))
    j += 1

print(len(ew))
for i in ew:
    print(' '.join(map(str, i)))