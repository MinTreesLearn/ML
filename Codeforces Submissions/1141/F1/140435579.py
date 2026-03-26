n = int(input())
A = list(map(int, input().split()))

from collections import defaultdict

D = defaultdict(lambda: [])
for r in range(n):
    s = 0
    for l in range(r, -1, -1):
        s += A[l]
        D[s].append((l, r))

k = 0
ans = -1
for s, LR in D.items():
    cand_k = 0
    cand_ans = []
    cur = -1
    for l, r in LR:
        if l <= cur:
            continue
        cur = r
        cand_ans.append((l+1, r+1))
        cand_k += 1
    if cand_k > k:
        k = cand_k
        ans = cand_ans
print(k)
for i in range(len(ans)):
    print(*ans[i])
