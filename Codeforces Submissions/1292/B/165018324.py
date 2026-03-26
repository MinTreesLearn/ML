import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
xy = [(x0, y0)]
x, y = x0, y0
while True:
    x *= ax
    x += bx
    y *= ay
    y += by
    if max(x - xs, y - ys) > t:
        break
    xy.append((x, y))
l = len(xy)
ans = 0
for i in range(l):
    x, y = xs, ys
    t0, cnt = 0, 0
    for j in range(i, l):
        xj, yj = xy[j]
        t0 += abs(x - xj) + abs(y - yj)
        x, y = xj, yj
        if t0 > t:
            break
        cnt += 1
        ans = max(ans, cnt)
for i in range(l - 1, -1, -1):
    x, y = xs, ys
    t0, cnt = 0, 0
    for j in range(i, -1, -1):
        xj, yj = xy[j]
        t0 += abs(x - xj) + abs(y - yj)
        x, y = xj, yj
        if t0 > t:
            break
        cnt += 1
        ans = max(ans, cnt)
print(ans)