# 10:47-

N,MOD = map(int, input().split())

fact = [1]*(N+1)
for i in range(1,N+1):
	fact[i] = fact[i-1]*i%MOD

ans = 0
for i in range(1,N+1):
	tmp = fact[i]*fact[N-i+1]*(N-i+1)
	ans += tmp
	ans %= MOD

print(ans)


