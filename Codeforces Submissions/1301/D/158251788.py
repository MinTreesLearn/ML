n, m, k = map(int, input().split())
out, max_ = [], 4 * n * m - 2 * n - 2 * m
if k > max_:
    exit(print('NO'))

for i in range(n - 1):
    if m > 1:
        cur = 'DUR' if i & 1 == 0 else 'DUL'
        out.append(f'{m - 1} {cur}')
    out.append('1 D')

if m > 1:
    ch = 'R' if n & 1 else 'L'
    out.append(f'{m - 1} {ch}')

for i in range(n, 0, -1):
    if m > 1:
        ch = 'L' if i & 1 else 'R'
        out.append(f'{m - 1} {ch}')
    if i > 1:
        out.append('1 U')

out2 = ['YES', '0']
for i in out:
    num, pat = i.split()
    num = int(num)

    if num * len(pat) >= k:
        div, mod = divmod(k, len(pat))
        if div:
            out2.append(f'{div} {pat}')
        if mod:
            out2.append(f'1 {pat[:mod]}')
        break

    k -= num * len(pat)
    out2.append(i)

out2[1] = str(len(out2) - 2)
print('\n'.join(out2))
