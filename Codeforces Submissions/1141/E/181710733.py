from itertools import accumulate
from math import ceil

H, n = map(int, input().split())

nums = list(map(int, input().split()))

prefixsum = list(accumulate(nums))

# find the min elmnt

the_min = -min(prefixsum)
last_change = -prefixsum[-1]
# calculate the iteration

turns = 0
if H > the_min and prefixsum[-1] < 0:
    turns = ceil((H - the_min)/last_change)
# print(turns)
H -= last_change * turns
ans = turns * n

# print(H)
for num in nums:
    ans += 1
    H += num
    if H <= 0:
        break

if H <= 0:
    print(ans)
else:
    print(-1)