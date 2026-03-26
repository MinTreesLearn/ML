import sys
import math

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 4 + 5)

test = False

mod1, mod2 = 10 ** 9 + 7, 998244353
inf = 10 ** 16 + 5
lim = 10 ** 5 + 5


def test_case():

    x0, y0, ax, ay, bx, by = map(int, input().split())
    xs, ys, t = map(int, input().split())

    x, y = [x0], [y0]

    while x[-1] * ax + bx <= xs + t and y[-1] * ay + by <= ys + t:

        x.append(x[-1] * ax + bx)
        y.append(y[-1] * ay + by)

    res = 0

    for i in range(len(x)):

        for j in range(len(x)):

            l, r = abs(x[i] - xs) + abs(y[i] - ys), abs(x[j] - x[i]) + abs(y[j] - y[i])

            if l + r <= t:

                res = max(res, abs(j - i) + 1)

    print(res)


t = 1

if test:

    t = int(input())

for _ in range(t):

    # print(f"Case #{_+1}: ", end='')
    test_case()
