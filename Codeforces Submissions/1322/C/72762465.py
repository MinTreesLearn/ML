from sys import stdin
from math import gcd
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

T = int(input())

for _ in range(T):
	n, m = map(int, input().split())
	values = list(map(int, input().split()))
	neigh_values = [0]*n
	y_neigh = [[] for i in range(n)]
	di = [[] for i in range(n)]
	for i in range(m):
		x, y = map(int, input().split())
		neigh_values[x - 1] += values[y - 1]
		di[x - 1].append(y - 1)
		y_neigh[y - 1].append(x - 1)



	# group indices with the same neighboring set 
	y_n = {}
	for i in range(n):
		nst = frozenset(y_neigh[i])
		if nst != set():
			if nst in y_n:
				y_n[nst].append(i)
			else:
				y_n[nst] = [i]

	curr = 0
	for nst in y_n.values():
		tosum = [values[i] for i in nst]
		curr = gcd(curr, sum(tosum))

	print (curr)

	if _ != T - 1:
		blank = input()


