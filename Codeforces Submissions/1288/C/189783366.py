# 14:26-
from itertools import accumulate

MOD = 10**9+7
N,M = map(int, input().split())

dp1 = list(accumulate([1]*N))
dp2 = [1]*N

for _ in range(1,M):
	dp1 = list(accumulate(dp1))
	cur = 0
	ndp2 = [0]*N
	for i in range(N-1,-1,-1):
		cur+=dp2[i]
		ndp2[i]=cur
	dp2 = ndp2

# print(dp1)
# print(dp2)

ans = 0
for i in range(N):
	ans+=dp1[i]*dp2[i]
	ans%=MOD
print(ans)


