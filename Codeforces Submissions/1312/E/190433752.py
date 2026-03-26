import sys
from array import array

input = lambda: sys.stdin.buffer.readline().decode().strip()
inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
Mint, Mlong, out = 2 ** 31 - 1, 2 ** 63 - 1, []


def shrink(l, r):
    stk = array('i')
    for i in range(l, r + 1):
        cur = a[i]
        while stk and stk[-1] == cur:
            stk.pop()
            cur += 1

        stk.append(cur)

    return len(stk) == 1


for _ in range(1):
    n, a = int(input()), array('i', inp(int))
    dp = array('i', list(range(1, n + 1)) + [0])

    for i in range(n):
        for j in range(i, -1, -1):
            if shrink(j, i): dp[i] = min(dp[i], dp[j - 1] + 1)

    out.append(dp[n - 1])
print('\n'.join(map(str, out)))
