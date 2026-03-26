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
	s = IS()
	last = s[0]
	string = ''
	ans = '1'
	for i in range(1, n):
		el = s[i]
		if el >= last:
			last = el
			ans += '1'
		else:
			string += el
			ans += '0'
	
	if list(sorted(list(string))) == list(string):
		print('YES')
		print(ans)
	else:
		print('NO')
	
	
if __name__ == '__main__':
	# for _ in range(II()):
	# 	main()
	main()
