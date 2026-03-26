
t = int(input())

for _ in range(t):

    n = int(input())

    s = list(input())

    count = 0
    mx = 0

    for i in range(len(s)):
        if s[i] == "A":
            for j in range(i+1, len(s)):
                if s[j] == "P":
                    count += 1
                else:
                    break
            mx = max(count,mx)
            count = 0
    print(mx)



	  		  	   	 			 	 	     	 	  	