tests = int(input())
i = 0
while i < tests:
	checker = False
	len_of_number = int(input())
	number = [int(x) for x in list(input())]
	if len_of_number == 1:
		print(-1)
	elif sum(number) == 1:
		print(-1)
	else:
		if sum(number)%2 == 0 and number[-1]%2 != 0:
			number = [str(x) for x in number]
			print(' '.join(number).replace(' ', ''))
		else:
			j = len_of_number - 1
			while j > 0:
				if number[j]%2 == 0:
					number.pop(j)
					#print(number)
					#j -= 1
				else:
					#print(sum(number))
					if sum(number)%2 == 0:
						#print('is it worked&!')
						number = [str(x) for x in number]
						print(' '.join(number).replace(' ', ''))
						break
					else:
						#print(number)
						k = len(number) - 2
						while k >= 0:
							if number[k]%2 != 0:
								number.pop(k)
								number = [str(x) for x in number]
								print(' '.join(number).replace(' ', ''))
								checker = True
								break
							k -= 1
				if checker == False:
					j -= 1
				else:
					break
			else:
				print(-1)
	i += 1