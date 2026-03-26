import bisect
import sys
input = sys.stdin.readline

t = int(input())
pow2 = [1]
for _ in range(20):
    pow2.append(2 * pow2[-1])
pow2 = set(pow2)
for _ in range(t):
    n, d = map(int, input().split())
    p = []
    d0 = []
    now = 0
    l, l0 = [1], [1]
    for i in range(2, n + 1):
        p.append(i // 2)
        if i in pow2:
            l.append(i)
            l0.append(i)
            now += 1
        d0.append(now)
    s = sum(d0)
    ans = "YES" if s <= d <= n * (n - 1) // 2 else "NO"
    print(ans)
    if ans == "NO":
        continue
    c = d - s
    for i in range(n, 0, -1):
        if not c:
            break
        if i in pow2:
            continue
        j = bisect.bisect_left(l, i) - 1
        for k in range(j, len(l0) - 1):
            if not c:
                break
            c -= 1
            p[i - 2] = l0[k]
            d0[i - 2] += 1
        if not c:
            break
        c -= 1
        p[i - 2] = l0[-1]
        d0[i - 2] += 1
        l0.append(i)
    print(*p)