s=int(input())
l=[]
for i in range(s):
	a=list(map(int,input().split()))
	l.append(a)
l.append(l[0])
if s%2==1:
	print ("NO")
	exit()
flag=0
for i in range(s//2,0,-1):
	x=[abs(l[i][0]-l[i-1][0]),abs(l[i][1]-l[i-1][1])]
	y=[abs(l[i+s//2][0]-l[i+s//2-1][0]),abs(l[i+s//2][1]-l[i+s//2-1][1])]
	if x!=y:
		print ("NO")
		flag=1
		break
if flag==0:
	print ("YES")
     			     		  	     			  	