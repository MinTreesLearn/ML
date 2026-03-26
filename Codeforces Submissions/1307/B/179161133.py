import math

def f():
    l1 = input().split(' ')
    l2 = input().split(' ')
    n = int(l1[0])
    x = int(l1[1])
    am = 0
    for i in range(n):
        if int(l2[i]) == x:
            print(1)
            return 0
        am = max(am, int(l2[i]))
    if am > x:
        print(2)
        return 0
    else:
        print(math.ceil(x/am))
        return 0


row = int(input())
for r in range(row):
    f()
	 				 	    	 			    				 			 	