t=int(input())
 
for k in range(t):
    n,x,yellow=map(int,input().split())
    print(max(1,min(n,x+yellow-n+1)),min(x+yellow-1,n))

 	 		 	  			 	    	 		   	