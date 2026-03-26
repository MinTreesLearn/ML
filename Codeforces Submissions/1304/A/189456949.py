for i in range(int(input())):
	x, y, a, b = map(int,input().split())
	r = -1
	if (y-x)%(a+b) < 1: r = (y-x)//(a+b)
	print(r)