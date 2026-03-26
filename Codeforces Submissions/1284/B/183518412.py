sequencias = int(input())
cont = 0
cresc = 0
ncresc = 0
maxi = []
mini = []
 
for x in range(sequencias):
    sequencia = str(input()).split()
    s = sequencia[1:]
    sint = [int(p) for p in s]
    for y in range(len(sint)):
        if y > 0 and sint[y] > sint[y-1]:
            cresc += 1
            break
        elif (y == len(sint) - 1):
            maxi.append(max(sint))
            mini.append(min(sint))
            ncresc += 1
cont = cresc * cresc + (cresc * ncresc * 2) 
mini.sort()
maxi.sort()
h = 0
 
for g in range(len(maxi)):
    while h < ncresc and int(mini[h]) < int(maxi[g]):
        h += 1
    cont += h
print(cont)
		 	  			 						 		  	 		 	   	