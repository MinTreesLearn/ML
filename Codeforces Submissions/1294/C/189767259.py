

t=int(input())
for x in range(t):
	n=int(input())
	i=2
	a=[]
	while(len(a)<2 and i*i<n):
		if n%i==0:
			n=n//i
			a.append(i)
		i=i+1
	if len(a)==2 and n not in a:
		print("YES")
		print(n,*a)
		
	else:
		print("NO")