import math
whatever = int(input())
for i in range(whatever):
    test_case = input().split()
    n = int(test_case[0])
    g = int(test_case[1])
    b = int(test_case[2])

    if g > n:
        print(n)
        continue

    total_days = 0
    # goo_days = 0
    ngood = math.ceil(n/2)

    check = False
    if ngood % g == 0:
        check = True
    divup = math.ceil(ngood / g)
    divdown = ngood // g
    #print(divup, divdown)

    if check:
        total_days += (divdown-1) * b
        total_days += divdown * g
        ngood -= divdown * g
    else:
        total_days += divdown * b
        total_days += divdown * g
        ngood -= divdown * g

    total_days += ngood
    if total_days < n:
        print(n)
        continue
    print(total_days)


	 			 	 		   			    	 	 				 		