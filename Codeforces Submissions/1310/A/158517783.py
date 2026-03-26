
n = int(input())
A = list(map(int,input().split()))
T = list(map(int,input().split()))
import heapq
nums = list(zip(A,T))
nums.sort(key=lambda x:(x[0],-x[1]))
# print(nums)
total = 0
res = 0
cur = -1
i = 0
heap = []
while i < n or heap:
	if not heap:
		cur = nums[i][0]
	
	while i < n and nums[i][0] == cur:
		heapq.heappush(heap,-nums[i][1])
		total += nums[i][1]
		i += 1
		
	total -= -heapq.heappop(heap)
	res += total
	cur += 1
	
print(res)