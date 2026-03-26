from __future__ import division, print_function
import io
import os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(input())
l = list(map(int, input().split()))

# not my solution, from: https://codeforces.com/contest/1299/submission/70653333
su = [l[0]]
cou = [-1, 0]
for k in range(1, n):
    nd = 1
    ns = l[k]
    while len(cou) > 1 and su[-1] * (cou[-1] - cou[-2] + nd) > (su[-1] + ns) * (
        cou[-1] - cou[-2]
    ):
        nd += cou[-1] - cou[-2]
        ns += su[-1]
        su.pop()
        cou.pop()
    cou.append(k)
    su.append(ns)

floats = []
for k in range(len(su)):
    floats += [su[k] / (cou[k + 1] - cou[k])] * (cou[k + 1] - cou[k])


if True:
    if False:
        # 3244 ms, TLE on pypy3
        # But 1044 ms on pypy2!!!
        print("\n".join(map(str, floats)))
    if False:
        # 2028 ms
        os.write(1, b"\n".join(str(x).encode() for x in floats))
    if False:
        # 1544 ms
        # %-formatting for bytes, added in python 3.5: https://www.python.org/dev/peps/pep-0461/
        os.write(1, b"\n".join(b"%.9f" % x for x in floats))
    if False:
        # 842 ms
        # Format with ints instead to avoid float formatting
        # This version is not generic! Doesn't handle negatives and wrong for stuff close to integers like x = 1.0 - 1e-10
        os.write(1, b"\n".join(b"%d.%09d" % (x, (x - int(x)) * 1e9 + 0.5) for x in floats))
    if False:
        # 748 ms
        # Same as above
        ans = bytearray()
        for x in floats:
            i = int(x)
            ans += b"%d.%09d\n" % (i, (x - i) * 1e9 + 0.5)
        os.write(1, ans)

    if True:
        # Try to handle sign and overflows in the fractional part
        # These edge cases are not exercised by this problem so I'm not sure if it's correct
        def floatToBytes(x):
            sign = b""
            if x < 0.0:
                sign = b"-"
                x *= -1.0
            whole = int(x)
            frac = int((x - whole) * 1e9 + 0.5)
            if frac >= 10 ** 9:
                frac -= 10 ** 9
                whole += 1
            return b"%b%d.%09d" % (sign, whole, frac)
        os.write(1, b'\n'.join(map(floatToBytes, floats)))

else:
    # 670 ms
    # Use that fact that most of the output are repeats (specific to this problem)
    ans = bytearray()
    for k in range(len(su)):
        repeat = cou[k + 1] - cou[k]
        x = su[k] / repeat
        i = int(x)
        ans += (b"%d.%09d\n" % (i, (x - i) * 1e9 + 0.5)) * repeat
    os.write(1, ans)
