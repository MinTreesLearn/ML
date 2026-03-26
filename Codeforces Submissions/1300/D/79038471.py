n = int(input())
if n % 2 == 1:
    print('NO')
else:
    m = n // 2
    raw = []
    for _ in range(n):
        raw.append(list(map(int,input().split())))
    for i in range(m):
        if raw[0][0]+raw[m][0] != raw[i][0]+raw[m+i][0] or raw[0][1]+raw[m][1] != raw[i][1]+raw[m+i][1]:
            print('NO')
            break
    else:
        print('YES')
#JSR
 			 		 				  		     		   	 		