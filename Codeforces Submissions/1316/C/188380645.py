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
	n, m, p = I()
	a, b = I(), I()
	for i in range(n):
		if a[i] % p != 0:
			idx_i = i
			break
	for i in range(m):
		if b[i] % p != 0:
			idx_j = i
			break
	print(idx_i + idx_j)


if __name__ == '__main__':
	# for _ in range(II()):
	# 	main()
	main()
#