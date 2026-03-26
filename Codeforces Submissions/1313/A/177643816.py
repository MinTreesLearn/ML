r = ""
for t in range(int(input())):
    a, b, c = sorted(list(map(int, input().split())), reverse=True)
    suma = 0
    if a > 0:
        a -= 1
        suma += 1
    if b > 0:
        b -= 1
        suma += 1
    if c > 0:
        c -= 1
        suma += 1
    if a > 0 and b > 0:
        a -= 1
        b -= 1
        suma += 1
    if a > 0 and c > 0:
        a -= 1
        c -= 1
        suma += 1
    if b > 0 and c > 0:
        b -= 1
        c -= 1
        suma += 1
    if a > 0 and b > 0 and c > 0:
        suma += 1
    r += f"{suma}\n"
print(r)
  	 		  	 			 	  	   		 		 		 	