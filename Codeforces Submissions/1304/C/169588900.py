for _ in range(int(input())):
	n,m=map(int,input().split())
	lo,hi=m,m
	t0=0
	ans="YES"
	for __ in range(n):
		t,l,h=map(int,input().split())
		lo-=t-t0;hi+=t-t0
		t0=t
		lo,hi=max(lo,l),min(hi,h)
		if lo>hi:ans="NO"
	print(ans)