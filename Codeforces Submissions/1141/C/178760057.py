n = int(input())
diff = list(map(int,input().split()))
nums = [1]
for i in diff:
    nums.append(nums[-1]+i)
mini = min(nums)
extra = 0
if mini<=0:
    extra = (-1)*mini + 1
for i in range(len(nums)):
    nums[i]+=extra
result = [i for i in range(1,n+1)]
if sorted(nums)==result:
    print(*nums)
else:
    print(-1)