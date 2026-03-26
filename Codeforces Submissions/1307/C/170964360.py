d={}
s=set()
for x in input():
 for y in s:d[x,y]=d.get((x,y),0)+d[y]
 s|={x};d[x]=d.get(x,0)+1
print(max(d.values()))
	 		   	   							 	  				    	

num_inp=lambda: int(input())
arr_inp=lambda: list(map(int,input().split()))
sp_inp=lambda: map(int,input().split())
str_inp=lambda:input()
