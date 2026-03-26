n, m = map(int, input().split())
a = list(map(int, input().split()))
 
if n > m: exit(print(0))
 
ans = 1
for i in range(n):
	for j in range(i+1, n):
		ans *= abs(a[i] - a[j])
		ans %= m
print(ans)