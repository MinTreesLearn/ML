for _ in range(int(input())):
  n = int(input())
  nums = list(map(int, input().split()))
  total = sum(nums)
  
  f = 0
  mx = nums[1]
  if mx >= total:
    print("NO")
    continue
  for i in range(2, len(nums)):
    mx = max(mx + nums[i], nums[i])
    if mx >= total:
      f = 1
      break

  if f:
    print("NO")
    continue

  mx = nums[-2]
  if mx >= total:
    print("NO")
    continue
  for i in range(len(nums)-3, -1, -1):
    mx = max(mx + nums[i], nums[i])
    if mx >= total:
      f = 1
      break

  if f:
    print("NO")
    continue

  print("YES")