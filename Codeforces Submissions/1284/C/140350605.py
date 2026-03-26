n,m=map(int,input().split())
ans=0
f=[1]
for i in range(1,n+2):f+=(f[-1]*i)%m,
for l in range(1,n+1):
	ans+=((f[n-l+2]-f[n-l+1])*f[l])%m
	ans%=m
print(ans)
