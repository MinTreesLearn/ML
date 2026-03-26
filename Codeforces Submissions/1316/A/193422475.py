t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	score = [int(x) for x in input().split()][:n]
	total = 0
	for i in range(n): total += score[i]
	print(min(m, total))
						    	  					     			 	 		