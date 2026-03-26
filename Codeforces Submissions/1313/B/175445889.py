t=int(input())
 
for k in range(t):
    n,x,yak=map(int,input().split())


    print(max(1,min(n,x+yak-n+1)),min(x+yak-1,n))

			 		 		    	 				  	  		  		