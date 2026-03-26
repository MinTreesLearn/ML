n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [0 for i in range(m)]
c = [0 for i in range(m)]
for i in a:
    b[i % m] += 1
    c[i % m] = i

for i in b:
    if (i > 1):
        print(0)
        exit()
# print([i for i in range(1, 10)])
tot = 1
for i in range(m):
    if b[i] == 1:
        for j in range(i + 1, m):
            if b[j] == 1:
                tot = tot * abs(c[j] - c[i]) % m
print(tot % m)
  		    	      	      	  		  		