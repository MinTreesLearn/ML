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
	
	two = []
	twotwo = 1
	for i in range(30):
		two.append(twotwo)
		twotwo *= 2
	two = two[::-1]
	
	queue = deque([(a, set(range(30)), 0)])
	ans = float('inf')
	
	while queue:
		m, s, h = queue.pop()
		c, idx, new_s = 0, -1, set()
		for i in s:
			first = (m[0] >> (29 - i)) & 1
			for j in m:
				if (j >> (29 - i)) & 1 != first:
					new_s.add(i)
					c += 1
					if idx == -1:
						idx = i
					break
		
		if c == 0:
			ans = min(ans, h)
		else:
			m1, m2 = [], []
			for i in range(len(m)):
				if (m[i] >> (29 - idx)) & 1 == 0:
					m1.append(m[i])
				else:
					m2.append(m[i])
			
			h += two[idx]
			new_s.remove(idx)
			if h <= ans:
				queue.append((m1, new_s.copy(), h))
				queue.append((m2, new_s.copy(), h))
	
	print(ans)


if __name__ == '__main__':
	# for _ in range(II()):
	# 	main()
	main()
