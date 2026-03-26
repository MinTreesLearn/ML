from collections import defaultdict
n = int(input())
nums = list(map(int, input().split()))
cnt = defaultdict(list)
for l in range(n):
    cur = 0
    for r in range(l, n):
        cur += nums[r]
        cnt[cur].append((l + 1, r + 1))
ans = 0
path = []
for arr in cnt.values():
    arr.sort(key=lambda x: x[1])
    last = cur = 0
    p = []
    for l, r in arr:
        if l > last:
            cur += 1
            last = r
            p.append([l, r])
    if ans < cur:
        ans = cur
        path = p
        
print(ans)
for l, r in path:
    print(l, r)
    
