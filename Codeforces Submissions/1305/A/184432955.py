T = int(input())
for _ in range(T):
	n = int(input())
	A = sorted(list(map(int, input().split())))
	B = sorted(list(map(int, input().split())))
 
	print(*A)
	print(*B)