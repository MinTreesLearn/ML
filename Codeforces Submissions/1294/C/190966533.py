t=int(input())

while(t):
	n=int(input())
	i=2
	flag=0
	while(i*i<=n):
		if n%i==0:
			d=n/i
			j=i+1
			# print(i,d)
			while(j*j<d):
				if d%j==0:
					flag=1
					print("YES")
					print(i,j,int(d/j))
					break
				j+=1	
		i+=1
		if flag==1:
			break

	if flag==0:
		print("NO")
					


	t-=1