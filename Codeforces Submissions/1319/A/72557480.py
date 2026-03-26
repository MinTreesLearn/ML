from math import ceil

n = int(input())
r = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

d = 0
for i in range(n):
	if r[i] < b[i]:
		d += 1
	
optimal_problems = 0
for i in range(n):
	if r[i] > b[i]:
		optimal_problems += 1
if optimal_problems == 0:
	print(-1)
else:
	print(ceil((d + 1) / optimal_problems))

