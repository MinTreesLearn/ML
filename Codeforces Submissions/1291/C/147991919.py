for i in range(int(input())):
	n,m,k=map(int,input().split())
	l=list(map(int,input().split()))
	k=min(k,m-1)
	t=m-k-1
	ans=0
	for i in range(k+1):
		l2=l[i:n-(k-i)]
		# print(i,l2)
		mx=max(l)
		for j in range(t+1):
			l3=l2[j:len(l2)-(t-j)]
			# print(i,j,l3)
			# print(max(l3[0],l3[-1]),min(ans,max(l3[0],l3[-1])))
			mx=min(mx,max(l3[0],l3[-1]))
		ans=max(ans,mx)
	print(ans)