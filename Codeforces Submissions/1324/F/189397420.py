import gc
import heapq
import itertools
import math
from collections import Counter, deque, defaultdict
from sys import stdout
import time
from math import factorial, log, gcd
import sys
from decimal import Decimal
import threading
from heapq import *
from fractions import Fraction
import bisect


def S():
	return sys.stdin.readline().split()


def I():
	return [int(i) for i in sys.stdin.readline().split()]


def II():
	return int(sys.stdin.readline())


def IS():
	return sys.stdin.readline().replace('\n', '')
	

def main():
	n = II()
	a = I()
	tree = [[] for _ in range(n)]
	for _ in range(n - 1):
		u, v = I()
		tree[u - 1].append(v - 1)
		tree[v - 1].append(u - 1)
	
	order = []
	queue = deque([0])
	p = [-1] * n
	d = [-1 if i == 0 else 1 for i in a]
	while queue:
		v = queue.pop()
		order.append(v)
		for u in tree[v]:
			if p[v] != u:
				p[u] = v
				queue.appendleft(u)
	order = order[::-1]
	up = [False] * n
	for i in range(n - 1):
		if d[order[i]] > 0:
			up[order[i]] = True
			d[p[order[i]]] += d[order[i]]
	
	ans = [0] * n
	ans[0] = d[0]
	for i in range(n - 2, -1, -1):
		idx = order[i]
		if not up[idx]:
			ans[idx] = max(d[idx], ans[p[idx]] + d[idx])
		else:
			ans[idx] = max(ans[p[idx]], d[idx])
	print(*ans)
	
	
			
	

if __name__ == '__main__':
	# for _ in range(II()):
	# 	main()
	main()