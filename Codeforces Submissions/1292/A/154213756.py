n, q = map(int,input().split())
a = [[0] * n for _ in range(2)]
bp = 0
for _ in range(q):
	x, y = map(int,input().split())
	x -= 1
	y -= 1
	u = 0
	if a[x][y] == 0:
	    u = 2
	else:
	    u = 1
	a[x][y] ^= 1
	for l in range(-1, 2):
		if 0 <= y + l < n and a[1 - x][y + l]:
			if u == 2:
			    bp += 1
			else:
			    bp -= 1
	print(["No","Yes"][bp == 0])