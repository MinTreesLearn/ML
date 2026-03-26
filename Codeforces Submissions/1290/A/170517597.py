for test in range(int(input())):
	n,m,k=map(int,input().split())
	a=list(map(int,input().split()))
	k=min(k,m-1)
	l=m-1-k
	resf=0
	for i in range(k+1):
		res=1<<33
		for j in range(l+1):
			res=min(max(a[i+j],a[i+j+n-m]),res)
		resf=max(res,resf)
	print(resf)