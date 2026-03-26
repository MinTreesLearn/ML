seq = int(input())
cresc = ncresc = h = 0
maxi = []
mini = []

for _ in range(seq):
    s = [int(p) for p in input().split()[1:]]
    c = False
    for i in range(1, len(s)):
        if s[i] > s[i-1]:
            cresc += 1
            c = True
            break
    if not c:
        maxi.append(max(s))
        mini.append(min(s))
        ncresc += 1

cresc = cresc * cresc + (cresc * ncresc * 2)
mini.sort()
maxi.sort()

for g in maxi:
    while h < ncresc and mini[h] < g:
        h += 1
    cresc += h
print(cresc)
  					 	 					 	   			  	  		