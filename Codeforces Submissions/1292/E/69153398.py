import sys
n, L, minID = None, None, None
s = []

def fill(id, c):
	global n, L, s, minID
	L -= (s[id] == 'L')
	s = s[0:id] + c + s[id+1:]
	minID = min(minID, id)

def query(cmd, str):
	global n, L, s, minID
	print(cmd, ''.join(str))
	print(cmd, ''.join(str), file=sys.stderr)
	sys.stdout.flush()
	if (cmd == '?'):
		result = list(map(int, input().split()))
		assert(result[0] != -1)
		for z in result[1:]:
			z -= 1
			for i in range(len(str)):
				assert(s[z+i] == 'L' or s[z+i] == str[i])
				fill(z+i, str[i])
	elif (cmd == '!'):
		correct = int(input())
		assert(correct == 1)

T = int(input())
for test_no in range(T):
	n = int(input())
	L, minID = n, n
	s = 'L' * n

	query('?', "CH")
	query('?', "CO")
	query('?', "HC")
	query('?', "HO")
	if (L == n):
		# the string exists in form O...OX...X, with X=C or X=H
		# or it's completely mono-character
		query('?', "CCC")
		if (minID < n): 
			for x in range(minID-1, -1, -1): fill(x, 'O')
		else:
			query('?', "HHH")
			if (minID < n):
				for x in range(minID-1, -1, -1): fill(x, 'O')
			else:
				query('?', "OOO")
				if (minID == n):
					# obviously n=4
					query('?', "OOCC")
					if (minID == n):
						fill(0, 'O')
						fill(1, 'O')
						fill(2, 'H')
						fill(3, 'H')
				
				if (s[n-1] == 'L'):
					t = s[0:n-1] + 'C'
					if (t[n-2] == 'L'): t = t[0:n-2] + 'C' + t[n-1:]
					query('?', t)
					if (s[n-1] == 'L'):
						fill(n-1, 'H')
						if (s[n-2] == 'L'): fill(n-2, 'H')
	else:
		maxID = minID
		while (maxID < n-1 and s[maxID+1] != 'L'): maxID += 1
		for i in range(minID-1, -1, -1):
			query('?', s[i+1:i+2] + s[minID:maxID+1])
			if (minID != i):
				for x in range(i+1): fill(x, 'O')
				break
		
		nextFilled = None
		i = maxID + 1
		while i < n:
			if (s[i] != 'L'):
				i += 1
				continue
			nextFilled = i
			while (nextFilled < n and s[nextFilled] == 'L'): nextFilled += 1
			query('?', s[0:i] + s[i-1])
			if (s[i] == 'L'):
				if (s[i-1] != 'O'): fill(i, 'O')
				else:
					if (nextFilled == n):
						query('?', s[0:i] + 'C')
						if (s[i] == 'L'): fill(i, 'H')
						for x in range(i+1, nextFilled): fill(x, s[i])
					else:
						for x in range(i, nextFilled): fill(x, s[nextFilled])
					i = nextFilled - 1
			i += 1
	query('!', s)