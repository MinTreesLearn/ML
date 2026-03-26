import bisect
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
s = list(map(int, input().split()))
mod = pow(10, 9) + 7
x = [[] for _ in range(n + 1)]
for i in range(n):
    x[s[i]].append(i + 1)
y = [[] for _ in range(n + 1)]
for _ in range(m):
    f, h = map(int, input().split())
    if len(x[f]) < h:
        continue
    y[f].append(h)
for i in range(1, n + 1):
    y[i].sort()
cntl, cntr = [0] * (n + 1), [0] * (n + 1)
for i in s:
    cntr[i] += 1
l0, r0 = [0] * (n + 1), [0] * (n + 1)
cnt = [0]
for i in range(1, n + 1):
    l = bisect.bisect_right(y[i], cntl[i])
    r = bisect.bisect_right(y[i], cntr[i])
    if r:
        cnt[0] += 1
        r0[i] = r
l1, r1 = list(l0), list(r0)
x = []
for i in s:
    cnt.append(cnt[-1])
    l, r = l0[i], r0[i]
    if l > r:
        l, r = r, l
    if 0 < l and 2 <= r:
        cnt[-1] -= 2
    elif max(l, r):
        cnt[-1] -= 1
    cntl[i] += 1
    cntr[i] -= 1
    l = bisect.bisect_right(y[i], cntl[i])
    r = bisect.bisect_right(y[i], cntr[i])
    l0[i], r0[i] = l, r
    x.append((l, r))
    if l > r:
        l, r = r, l
    if 0 < l and 2 <= r:
        cnt[-1] += 2
    elif max(l, r):
        cnt[-1] += 1
ans = [max(cnt), 0]
ans0 = 1
now = []
for i in r1:
    now.append(max(1, i))
    ans0 *= now[-1]
    ans0 %= mod
if ans[0] == cnt[0]:
    ans[1] = ans0
for i in range(n):
    j = s[i]
    l, r = x[i]
    l0, r0 = l1[j], r1[j]
    l1[j], r1[j] = l, r
    ans0 *= pow(now[j], mod - 2, mod)
    ans0 %= mod
    if ans[0] ^ cnt[i + 1] or cnt[i] ^ cnt[i + 1]:
        if l > r:
            l, r = r, l
        if 0 < l and 2 <= r:
            now[j] = l * (r - 1) % mod
        else:
            now[j] = l + r
        now[j] = max(now[j], 1)
        ans0 *= now[j]
        ans0 %= mod
        if ans[0] == cnt[i + 1]:
            ans[1] += ans0
            ans[1] %= mod
    else:
        if 0 < min(l, r) and 2 <= max(l, r):
            c = 0
            for k in range(l0 + 1, l + 1):
                if k <= r:
                    c += r - 1
                else:
                    c += r
        else:
            c = l - l0
        ans[1] += ans0 * c % mod
        ans[1] %= mod
        if l > r:
            l, r = r, l
        if 0 < l and 2 <= r:
            now[j] = l * (r - 1) % mod
        else:
            now[j] = l + r
        now[j] = max(now[j], 1)
        ans0 *= now[j]
        ans0 %= mod
sys.stdout.write(" ".join(map(str, ans)))