t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(input().split())
    found = False
    contains = set()
    for i in range(1, n):
        if nums[i] in contains:
            found = True
        contains.add(nums[i-1])
    if found:
        print("YES")
    else:
        print("NO")