for _ in range(int(input())):
	x,y,a,b=[int(_) for _ in input().split()]
	print((y-x)//(a+b) if (y-x)%(a+b)==0 else -1)