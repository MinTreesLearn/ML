from sys import stdin
from itertools import accumulate
input = stdin.readline

n = int(input())
q = list(map(int, input().split()))
psum = list(accumulate(q)); min_ind = 0; min_val = 0
for i in range(len(psum)):
    if psum[i] <= min_val:
        min_ind = i + 1; min_val = psum[i]

psum = [0] + psum
#1 <=> psum[min_ind]

off = 0; offs = [0]
for elem in q:
    off = (off + elem) % n
    offs.append(off)

if len(set(offs)) != len(offs) or max(psum) > n - 1:
    print(-1)
else:
    ans = [0 for i in range(n)]
    for i in range(n): ans[i] = (psum[i] - min_val) + 1
    if not 1 <= max(ans) <= n:
        print(-1)
    else:
        print(' '.join(str(num) for num in ans))
