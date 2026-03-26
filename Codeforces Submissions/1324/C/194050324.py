cases = int(input())


for c in range(cases):
    jumps = input()

    pos_r = []
    pos_r.append(0)
    for i in range(len(jumps)):
        if (jumps[i] == 'R'):
            pos_r.append(i+1)

    pos_r.append(len(jumps) + 1)

    r = 0
    
    for h in range(len(pos_r) - 1):
        r = max(r, pos_r[h+1]-pos_r[h])
    
    print(r)

			  								  	   	      		 	