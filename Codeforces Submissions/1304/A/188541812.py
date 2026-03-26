t=int(input())
for i in range(t):
	x,y,a,b=map(int,input().split())
	k=(y-x)%(a+b)
	if k:
		print(-1)
	else:
		print((y-x)//(a+b))