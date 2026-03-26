n = int(input())
minimos, maximos = [], []
asc, nasc = 0, 0

for i in range(n):
    sequencia = list(map(int, input().split(" ")))[1:]
    for j in range(len(sequencia)):
        if j > 0 and sequencia[j] > sequencia[j - 1]:
            asc += 1
            break
        elif j == len(sequencia) - 1:
            nasc += 1
            minimos.append(min(sequencia))
            maximos.append((max(sequencia)))

total = asc * asc + 2 * asc * nasc
minimos.sort()
maximos.sort()

i = 0
for k in maximos:
    while i < nasc and minimos[i] < k:
        i += 1
    total += i

print(total)

 				 							  	 		   		 	 	