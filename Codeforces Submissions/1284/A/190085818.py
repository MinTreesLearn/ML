n,m=map(int,input().split())
a=input().split()
b=input().split()
for i in range(int(input())):
	y=int(input())
	print(a[y%n-1]+b[y%m-1])