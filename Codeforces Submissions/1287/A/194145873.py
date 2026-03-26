t = int(input())

for i in range(t):
    k = int(input())
    a = input()
    angry = False
    patient = 0
    ans = 0
    for j in range(len(a)):
        if a[j] == 'A':
            angry = True
            ans = max(ans, patient)
            patient = 0
        elif a[j] == 'P' and angry:
            patient += 1
    ans = max(ans, patient)

    print(ans)

 	  	  	 		 		 		  							  			