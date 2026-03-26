for i in range(int(input())):
	n,m = map(int,input().split())
	arr = map(int,input().split())
	print(min(m,sum(arr)))