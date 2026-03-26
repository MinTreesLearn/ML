n = int(input())
nums = list(map(int, input().split()))

ans = float('-inf')
idx = 0

for piv in range(len(nums)):
    tot = nums[piv]
    m = tot
    for i in range(piv-1, -1, -1):
        m = min(m, nums[i])
        tot += m
    m = nums[piv]
    for i in range(piv+1, len(nums)):
        m = min(m, nums[i])
        tot += m
    
    if tot > ans:
        ans = tot
        idx = piv

m = nums[idx]
for i in range(idx-1, -1, -1):
    m = min(m, nums[i])
    nums[i] = m

m = nums[idx]
for i in range(idx+1, len(nums)):
    m = min(m, nums[i])
    nums[i] = m

print(' '.join([str(i) for i in nums]))