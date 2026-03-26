t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    lst = [int(x) for x in input().split()][:n]
    sum  = 0
    for i in range(n):
        sum += lst[i]
    print(min(m, sum))
 			 	  									 		  				  	