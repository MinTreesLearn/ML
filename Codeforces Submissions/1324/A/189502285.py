for i in range(int(input())):
	n = int(input())
	cnto = sum(list(map(lambda x: int(x) % 2, input().split())))
	print('YES' if cnto == 0 or cnto == n else 'NO')