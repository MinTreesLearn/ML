for _ in range(int(input())):
  string = input()
  len_max = 0
  len = 0
  for i in string:
    if i == 'R':
      len = 0
    else:
      len += 1
      if len > len_max:
        len_max = len
  print(len_max + 1)

  	 	   					  		  	  	 	 		  	