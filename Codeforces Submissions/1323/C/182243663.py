n = int(input())
s = str(input())
x, y, ans, z = int(0), int(0), int(0), int(0)
for i in s:
    if i == '(':
        x += 1
        z += 1
    else:
        y += 1
        if z > 0:
            z -= 1
    if x == y:
        if z != 0:
            ans += x + y
        x, y, z = 0, 0, 0
if x != y:
    print(-1)
else:
    print(ans)
        				  		 	  		  	 		  	