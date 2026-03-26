
def ncr(n, r, p):
	num = den = 1
	for i in range(r):
		num = (num * (n - i)) % p
		den = (den * (i + 1)) % p
	return (num * pow(den,
			p - 2, p)) % p




n,m=map(int, input().split())
md=998244353 
if n==2:
    print(0)
else:
    ans=ncr(m,n-1,md)
    ans=(ans*(n-2))%md
    ans=(ans*pow(2,n-3,md))%md
    print(ans)