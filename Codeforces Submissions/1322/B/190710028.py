import sys
from array import array

input = lambda: sys.stdin.buffer.readline().decode().strip()
inp = lambda dtype: [dtype(x) for x in input().split()]
debug = lambda *x: print(*x, file=sys.stderr)
ceil1 = lambda a, b: (a + b - 1) // b
Mint, Mlong, out = 2 ** 31 - 1, 2 ** 63 - 1, []

for _ in range(1):
    Max, ans = 10 ** 7, 0
    n, a = int(input()), array('i', inp(int))
    mem = array('i', [0] * (Max + 10))

    for bit in range(25):
        mod, ones = 1 << (bit + 1), 0
        for i in range(n): mem[a[i] % mod] += 1
        for i in range(min(mod * 2, Max + 1)): mem[i] += mem[i - 1]

        for i in range(n):
            lo = max((1 << bit) - (a[i] % mod), 0)
            if lo <= Max:
                hi = min(mod - 1 - (a[i] % mod), Max)
                ones += mem[hi] - mem[lo - 1] - (lo <= a[i] % mod <= hi)

            lo = mod + (1 << bit) - (a[i] % mod)
            if lo <= Max:
                hi = min(mod * 2 - 2 - (a[i] % mod), Max)
                ones += mem[hi] - mem[lo - 1] - (lo <= a[i] % mod <= hi)

        ans |= ((ones >> 1) & 1) << bit
        for i in range(min(mod * 2, Max + 1)): mem[i] = 0

    out.append(ans)
print('\n'.join(map(str, out)))
