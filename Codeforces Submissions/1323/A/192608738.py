t=int(input())
for k in range(t):
	n=int(input())
	a=[*map(int,input().split())]
	#print(a)
	kt=False; kq=-1; s=[]
	for i in range(n):
		if a[i]%2==0 : 
			s.append(i+1)
			kt=True
			break
	if kt :
		print(len(s))
		print(*s)
	else :
		for i in range(n):
			if a[i]%2!=0 : 
				s.append(i+1)
				if len(s) >1 : break
		if len(s) <2 : print(-1)
		else : 
			print(len(s))
			print(*s)