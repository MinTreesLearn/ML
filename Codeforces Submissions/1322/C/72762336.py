from collections import Counter 
from sys import stdin
from math import gcd
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

T = int(input())

for _ in range(T):
	n, m = map(int, input().split())
	values = list(map(int, input().split()))
	y_neigh = [[] for i in range(n)]
	for i in range(m):
		x, y = map(int, input().split())
		y_neigh[y - 1].append(x - 1)



	# group indices with the same neighboring set 
	'''
	y_n = {}
	for i in range(n):
		nst = frozenset(y_neigh[i])
		if nst != set():
			if nst in y_n:
				y_n[nst] += values[i]
			else:
				y_n[nst] = values[i]
	'''
	# using Counter here for faster read 
	y_n = Counter()
	for i in range(n):
		if y_neigh[i] != []:
			y_n[hash(tuple(sorted(y_neigh[i])))] += values[i]


	curr = 0
	for g in y_n:
		if g == hash(tuple()):
			continue
		curr = gcd(curr, y_n[g])

	print (curr)
	blank = input()


