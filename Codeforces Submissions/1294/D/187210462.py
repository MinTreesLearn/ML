q,x=map(int,input().split())
a,m,s=[0]*(x+1),0,""
while q>0:
	q-=1
	a[int(input())%x]+=1
	while a[m%x]>0:
		a[m%x]-=1
		m+=1
	s+=(str(m)+"\n")
print(s)