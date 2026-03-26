test = int(input())
for t in range(test):
	n = int(input())
	s = input()
	m = {}
	x = 0
	y = 0
	c = False
	r = -1
	l = -1
	lnn = 1000000
	m[(x,y)] = 0
	for i in range(n):
		if s[i] == "R":
			x += 1
		if s[i] == "L":
			x -= 1
		if s[i] == "U":
			y += 1
		if s[i] == "D":
			y -= 1
		if (x,y) in m:
			ln = i - m[(x,y)]+1
			if ln < lnn:
				lnn = ln
				l = m[(x,y)]+1
				r = i + 1
			c = True
		m[(x,y)] = i + 1
	if not c:
		print(-1)
	else:
		print(l,r)
			