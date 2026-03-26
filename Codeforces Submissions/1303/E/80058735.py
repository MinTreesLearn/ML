def problem(s, p):
    for i in range(len(p)):
        l = p[:i] + ' '
        r = p[i:] + ' '
 
        dp = [0] + [None] * i
 
        for x in s:
            for j in range(i, -1, -1):
                if dp[j] is None:
                    continue
 
                if l[j] == x:
                    dp[j + 1] = dp[j] if dp[j + 1] is None else max(dp[j], dp[j + 1])
 
                temp = r[dp[j]]
                if r[dp[j]] == x:
                    dp[j] += 1
 
        if dp[-1] == len(r) - 1:
            return 'YES'
 
    return 'NO'
 
 
for _ in range(int(input())):
    print(problem(input(), input()))

			 	 	   	  	     			    			 	