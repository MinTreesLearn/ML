for cases in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	z=a.count(0)
	s=z+sum(a)
	if s==0:
	    print(z+1)
	else:
	    print(z)