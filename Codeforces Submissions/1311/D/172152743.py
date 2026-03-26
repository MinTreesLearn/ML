for _ in range(int(input())):
	a,b,c=map(int,input().split())
	x=float("inf")
	s,d,f=0,0,0
	w=[]
	for i in range(1,11000):
		for j in range(i,11000,i):
			for k in range(j,11000,j):
				t=abs(a-i)+abs(b-j)+abs(c-k)
				if t<x:
					x=t
					s,d,f=i,j,k
	print(x)
	print(str(s)+' '+str(d)+" "+str(f))