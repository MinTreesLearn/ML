def resort(seq):
    if seq.count("(") != seq.count(")"):
        print("-1")
        return
    
    count = 0
    state = 0
    prev = 0
    for i in seq:
        if i == '(':
            state += 1
        else:
            state -= 1
        if state < 0:
            count += 1
        elif state == 0 and prev < 0:
            count += 1
        prev = state
    if state != 0:
        print(-1)
    else:
        print(count)

seq_length = input()
resort(input())
	 		 	  	 		        	 		  	 		