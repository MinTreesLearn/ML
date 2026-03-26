import math

def inp(sa):
	b=[]
	j=0	
	for i in range(len(sa)):
		if sa[i]==" ":
			b.append(int(sa[j:i]))
			j=i+1
	b.append(int(sa[j:]))
	return b

def iskpow(n,k):
	basek=[]
	i=0
	while n!=0:
		temp=n%k
		if temp>1:
			return 0
		if temp==1:
			basek.append(i)
		n=n//k
		i+=1
	return basek
	
t=int(input())
def lyans():

	temp=input()
	temp=inp(temp)
	k=temp[1]
	a=input()
	a=inp(a)
	listk=[]
    
	for i in a:
		if i==0:
			continue
		m=iskpow(i,k)
		if isinstance(m,list) :
			listk+=m
		else:
			print("NO")
			return 0
	if len(set(listk))==len(listk):
		print("YES")
	else:
		print("NO")	      	    
       	
for ti in range(t):
	lyans()