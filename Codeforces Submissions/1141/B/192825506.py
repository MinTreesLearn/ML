n = int(input())
a = [int(x) for x in input().split()][:n]
count, max = 0, 0
check1, check2 = False, False
start, end = 0, 0
for i in range(n): 
	if a[i] == 1: 
		count += 1 
		if check1 == False:
			start += 1
	else: 
		count = 0
		check1 = True
	if count > max: max = count
for i in reversed(range(n)):
	if a[i] == 1 and check2 == False: end += 1
	else: break
if start + end > max: max = start + end
print(max)
  	 	  	 	 		  	 	 	  	  	 			