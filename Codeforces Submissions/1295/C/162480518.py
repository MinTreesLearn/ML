from bisect import bisect_right as br
from collections import defaultdict
from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    s = list(input())
    t = input()
    d = defaultdict(list)
    for i, c in enumerate(s):
        d[c].append(i)
    res = 1
    prev = -1
    for i in t:
        if not d[i]:
            res = -1
            break
        temp = br(d[i], prev)
        if temp >= len(d[i]):
            res += 1
            prev = d[i][0]
        else:
            prev = d[i][temp]
    print(res)
