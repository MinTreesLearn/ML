t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    s = input()
    ang, mx, cnt = 0, 0, 0
    for i in range(n):
        if s[i] == 'A':
            ang = 1
            mx = max(mx, cnt)
            cnt = 0
        elif ang and s[i] == 'P':
            cnt += 1
    mx = max(mx, cnt)
    print(mx)
  	   		 		  			 		 	   	 		  	