import sys
from array import array

input = lambda: sys.stdin.buffer.readline().decode().strip()

n = int(input())

if n & 1:
    exit(print('no'))

ys, xs = array('i'), array('i')
for _ in range(n):
    x, y = map(int, input().split())
    ys.append(y)
    xs.append(x)

curx, cury = 1e9 + 1, 1e9 + 1
for i in range(n // 2):
    l, r = i, i + n // 2
    mx = abs(xs[l] - xs[r]) + 2 * min(xs[l], xs[r])
    my = abs(ys[l] - ys[r]) + 2 * min(ys[l], ys[r])

    if (curx == cury == 1e9 + 1) or curx == mx and cury == my:
        curx, cury = mx, my
    else:
        exit(print('no'))

print('yes')
