# 13:17-
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

cnt = [0]*32
for i in range(32):
	for a in A:
		if a&(1<<i):
			cnt[i]+=1

find = -1
for i in range(31,-1,-1):
	if cnt[i]==1:
		find = i
		break

if find>=0:
	idx = 0
	for i in range(N):
		if A[i]&(1<<find):
			idx = i
			break

	A = A[idx:] + A[:idx]

print(*A)
