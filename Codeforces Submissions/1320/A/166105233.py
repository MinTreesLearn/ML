from collections import Counter
n = int(input())
b = list(map(int, input().split()))
b1 = b.copy()
dct = {}
for i in range(n):
    b1[i] -= (i + 1)
for i, item in enumerate(b1):
    if item in dct:
        dct[item] += b[i]
    else:
        dct[item] = b[i]
l = list(dct.values())
l.sort(reverse=True)
print(l[0])