from math import ceil

T = int(input())

for test in range(T):
    n, d = [int(i) for i in input().split()]
    if d <= n:
        print("YES")
        continue

    for x in range(n):
        if ceil(d/(x+1)) <= n-x:
            print("YES")
            break
    else:
        print("NO")
			    	  	 		    	 		  	 			 	