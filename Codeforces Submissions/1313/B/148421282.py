for i in range(int(input())):
	n,a,b=map(int,input().split())
	if((a+b)<(n+1)):
		print(1,end=" ")
	else:
		print(min((a+b)-n+1,n),end=" ")
	print(min(a+b-1,n))