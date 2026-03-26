t = int(input())
for _ in range(t):
	n, d = map(int, input().strip().split())
	a = list(map(int, input().strip().split()))
	for i in range(1, n):
		if d == 0:
			break
		if a[i] == 0:
			continue
		if a[i] * i <= d:
			a[0] += a[i]
			d -= a[i] * i
		else:
			for j in range(a[i]-1, 0, -1):
				if j * i <= d:
					a[0] += j
					d -= j * i
					break
	print(a[0])
			
