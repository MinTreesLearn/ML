t= int(input())
for counter in range(t):
    array = [int(x) for x in input().split()]
    allowed = array[0] // 2
    finished = 0
    g = array[1]
    b = array[2]
    
    cycle = g + b
    progress = cycle * (allowed // b)
    ans = progress
    leftover = allowed % b
    remaining = array[0] - progress
    if remaining <= g + leftover:
        ans += remaining
    else:
        ans += cycle
        progress += g + leftover
        remaining = array[0] - progress
        if remaining % g == 0:
            ans += (remaining // g) * cycle - b
        else:
            ans += (remaining // g) * cycle + (remaining % g)
    print(ans)
    
 	  		 		 		 		    		   		 	 		