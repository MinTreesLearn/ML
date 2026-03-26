import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
pow2 = [1]
for _ in range(63):
    pow2.append(2 * pow2[-1])
d = dict()
for i in range(32):
    d[pow2[i]] = i
ans = []
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    if sum(a) < n:
        ans0 = -1
        ans.append(ans0)
        continue
    c = [0] * 63
    for i in a:
        c[d[i]] += 1
    ans0 = 0
    for i in range(63):
        if n < pow2[i]:
            break
        if i:
            c[i] += c[i - 1] // 2
        if not pow2[i] & n:
            continue
        if not c[i]:
            for j in range(i + 1, 63):
                ans0 += 1
                if c[j]:
                    k = j
                    break
            for j in range(k, i, -1):
                c[j] -= 1
                c[j - 1] += 2
        c[i] -= 1
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))