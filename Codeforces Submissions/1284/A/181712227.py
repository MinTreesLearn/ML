n = [int(i) for i in input().split(" ")]
a = input().split(" ")
b = input().split(" ")

t = int(input())

for i in range(t):
    year = int(input())

    print(a[year%(n[0]) - 1]+b[year%(n[1]) - 1])
  	 		 		  		 		 	 				  	  		