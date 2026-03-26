from sys import stdin
from math import ceil
inp = stdin.readline

h, n = map(int, inp().split())
arr = [int(x) for x in inp().split()]

change = sum(arr)
ma = 0
count = 0
poi = []
hp = []
for i, c in enumerate(arr):
    count += c
    if count < ma:
        poi.append(i)
        hp.append(count)
        ma = count

if change >= 0 and h + ma > 0:
    print(-1)
else:
    if change >= 0 or h + ma <= 0:
        x = 0
    else:
        x = ceil((-ma-h)/change)

    h += x*change

    for i, c in enumerate(hp):
        if h + c <= 0:
            print(poi[i] + x*n + 1)
            break


