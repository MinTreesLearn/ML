from math import ceil
testcases = int(input())

results = []
for i in range(testcases):
    [n, g, b] = [int(num) for num in input().split()]
    threshold = ceil(n / 2)
    min_cycles = threshold // g

    result = (min_cycles - 1) * (g + b) + g

    if min_cycles * g < threshold:
        result += b + (threshold - min_cycles * g)

    if result < n:
        result = n

    results.append(int(result))

for i in results:
    print(i)
	 	 	 	 		  	  		   	   	   		