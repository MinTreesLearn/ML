x0, y0, ax, ay, bx, by = list(map(int, input().split()))
xs, ys, T = list(map(int, input().split()))
x = [x0]
y = [y0]
for i in range(1, 100):
    x.append(ax * x[i - 1] + bx)
    y.append(ay * y[i - 1] + by)
ans = 0
for i in range(100):
    t = T
    t -= abs(xs - x[i])
    t -= abs(ys - y[i])
    cnt1, cnt2 = 0, 0
    if (t >= 0):
        cnt1 += 1
        cnt2 += 1
    else:
        continue
    t1, t2 = t, t
    for j in range(i + 1, 100):
        t1 -= abs(x[j] - x[j - 1])
        t1 -= abs(y[j] - y[j - 1])
        if (t1 >= 0):
            cnt1 += 1
        else:
            break
    for j in range(i - 1, -1, -1):
        t2 -= abs(x[j] - x[j + 1])
        t2 -= abs(y[j] - y[j + 1])
        if (t2 >= 0):
            cnt2 += 1
        else:
            break
    ans = max(ans, cnt1)
    ans = max(ans, cnt2)
print(ans)
