for run in range(int(input())):
    a,b,x,y=map(int,input().split())
    left=x*b
    right=(a-1-x)*b
    top=a*y
    down=(a*(b-1-y))
    print(max(left,right,top,down))
 			   		  			     	 	 	 		 	 	