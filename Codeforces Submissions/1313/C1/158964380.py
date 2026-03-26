n=int(input())
l=list(map(int,input().split()));su=0;ans=[]
for i in range(n):
    t=l[::]
    for j in range(i-1,-1,-1):t[j]=min(t[j],t[j+1])
    for j in range(i+1,n):t[j]=min(t[j],t[j-1])
    if sum(t)>su:
        su=sum(t);ans=t
print(*ans)
		   					 			  	 			  			  	