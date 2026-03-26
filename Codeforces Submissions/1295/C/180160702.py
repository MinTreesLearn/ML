import sys
input = sys.stdin.readline
from bisect import bisect


def f(x):
    return ord(x)-97


for _ in range(int(input())):
    s = input()[:-1]
    t = input()[:-1]
    d = [[] for i in range(26)]
    for i, j in enumerate(s):
        d[f(j)].append(i)
    w = [len(d[i]) for i in range(26)]
    c = 1
    p = -1
    for i in t:
        if w[f(i)] == 0:
            print(-1)
            break
        a = bisect(d[f(i)], p)
        if a == 0:
            p = d[f(i)][0]
        elif a == w[f(i)]:
            c += 1
            p = d[f(i)][0]
        else:
            p = d[f(i)][a]
    else:
        print(c)