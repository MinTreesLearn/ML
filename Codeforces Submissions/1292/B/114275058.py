T = 1
for test_no in range(T):
    x0, y0, ax, ay, bx, by = map(int, input().split())
    xs, ys, t = map(int, input().split())

    LIMIT = 2 ** 62 - 1
    x, y = [x0], [y0]
    while ((LIMIT - bx) / ax >= x[-1] and (LIMIT - by) / ay >= y[-1]):
        x.append(ax * x[-1] + bx)
        y.append(ay * y[-1] + by)

    n = len(x)
    ans = 0
    for i in range(n):
        for j in range(i, n):
            length = x[j] - x[i] + y[j] - y[i]
            dist2Left = abs(xs - x[i]) + abs(ys - y[i])
            dist2Right = abs(xs - x[j]) + abs(ys - y[j])
            if (length <= t - dist2Left or length <= t - dist2Right): ans = max(ans, j - i + 1)

    print(ans)