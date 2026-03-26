x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

def dist(x1, y1, x2, y2):
    return abs(x1-x2)+abs(y1-y2)

n = 70
x = [0]*n
y = [0]*n

x[0] = x0
y[0] = y0

for i in range(1, n):
    x[i] = ax*x[i-1]+bx
    y[i] = ay*y[i-1]+by

ans = 0
for i in range(n):
    res = 0
    time = t
    if dist(xs, ys, x[i], y[i]) <= time:
        res += 1
        time -= dist(xs, ys, x[i], y[i])
    else:
        ans = max(ans, res)
        continue

    for j in range(i, -1, -1):
        if dist(x[j], y[j], x[j-1], y[j-1]) <= time:
            time -= dist(x[j], y[j], x[j-1], y[j-1])
            res += 1
        else:
            break
    for j in range(1, n):
        if dist(x[j], y[j], x[j-1], y[j-1]) <= time:
            time -= dist(x[j], y[j], x[j-1], y[j-1])
            if j > i:
                res += 1
        else:
            break
    ans = max(ans, res)

print(ans)
