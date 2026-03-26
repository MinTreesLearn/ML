# AOJ CGL_4_A "Convex Hull"

def ConvexHull(Points):
    Qs = []
    for x, y in Points:
        while len(Qs) > 1:
            x1, y1 = Qs[-1]
            x2, y2 = Qs[-2]
            if (y1-y)*(x-x2) > (y-y2)*(x1-x):
                Qs.pop()
            else:
                break
        Qs.append((x, y))

    return Qs

import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

Points = [(0, 0)]
tmp = 0
for i, a in enumerate(A):
    tmp += a
    Points.append((i+1, tmp))

C = ConvexHull(Points)

ans = []
# pre = 0
# tpre = 0
# for ind, t in C:
#     if ind == 0: continue
#     ans += [(t-tpre)/(ind-pre)]*(ind-pre)
#     pre = ind
#     tpre = t
for i in range(len(C)-1):
    count = C[i+1][0]-C[i][0]
    value = C[i+1][1]-C[i][1]
    print((str(value/count) + "\n")*count, end="")