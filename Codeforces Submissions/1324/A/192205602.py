
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    odd = 0
    even = 0
    for i in a:
        if i%2 == 0:
            even += 1
        else:
            odd += 1
    if odd == 0 or even == 0:
        print("YES")
    else:
        print("NO")


  	 			  			  					   	    	  	