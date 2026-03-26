import sys
from array import array


def center_symmetry(xs, ys):
    if len(xs) & 1:
        return 0
    curx, cury = 1e9 + 1, 1e9 + 1
    for i in range(n // 2):
        l, r = i, i + n // 2
        mx = abs(xs[l] - xs[r]) + 2 * min(xs[l], xs[r])
        my = abs(ys[l] - ys[r]) + 2 * min(ys[l], ys[r])

        if (curx == cury == 1e9 + 1) or curx == mx and cury == my:
            curx, cury = mx, my
        else:
            return 0
    return curx, cury


input = lambda: sys.stdin.buffer.readline().decode().strip()

n = int(input())
ys, xs = array('i'), array('i')
for _ in range(n):
    x, y = map(int, input().split())
    ys.append(y)
    xs.append(x)

ret = center_symmetry(xs, ys)
print('no' if not ret else 'yes')
