from math import inf
n, h, l, r = map(int, input().split())
nums = list(map(int, input().split()))
f = [-inf]*h
f[0] = 0
for i, x in enumerate(nums):
    g = [-inf]*h
    for s in range(h):
        g[s] = max(f[(s-x)%h], f[(s-x+1)%h])+(l<=s<=r)
    f = g
print(max(f))
