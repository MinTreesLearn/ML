input()
a=input().split()
print(a.pop(next((x for x in zip(*(f'{int(x):30b}'for
x in a))if x.count('1')==1),'1').index('1')),*a)
	 			  		 	  			     			  		  	