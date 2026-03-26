import sys
input = sys.stdin.read().split('\n')
t = int(input[0])
del input[0]
test_cases = [[int(x) for x in y.split()] for y in input]
if test_cases[len(test_cases) - 1] == []:
    del test_cases[len(test_cases) - 1]

for a, b, c in test_cases:
    total = 0
    if a>0:
        total += 1
        a -= 1
    if b>0:
        total += 1
        b -= 1
    if c>0:
        total += 1
        c -= 1

    
    if a==1 and b==1 and c>1:
        total += 2
        a -= 1
        b -= 1
        c -= 2
    elif a==1 and b>1 and c==1:
        total += 2
        a -= 1
        b -= 2
        c -= 1
    elif a>1 and b==1 and c==1:
        total += 2
        a -= 2
        b -= 1
        c -= 1
    else:
        if a>0 and b>0:
            total += 1
            a -= 1
            b -= 1
        if b>0 and c>0:
            total += 1
            b -= 1
            c -= 1
        if a>0 and c>0:
            total += 1
            a -= 1
            c -= 1

    
    if a>0 and b>0 and c>0:
        total += 1
    
    print(total)
		   	   	   		  		  	 	  			 	