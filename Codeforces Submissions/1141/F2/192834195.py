from collections import defaultdict
n = int(input())
nums = list(map(int, input().split()))
d = defaultdict(list)
for i in range(n):
    s = 0
    for j in range(i, n):
        s += nums[j]
        d[s].append((i+1, j+1))
res = []
for a in d.values():
    if len(a)<=len(res):
        continue
    a.sort(key=lambda x:x[1])
    tmp = []
    i = 0
    for l, r in a:
        if l>i:
            tmp.append((l, r))
            i = r
    if len(tmp)>len(res):
        res = tmp
print(len(res))
print('\n'.join(map(lambda x: f'{x[0]} {x[1]}', res)))
