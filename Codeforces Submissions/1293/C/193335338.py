from sys import stdin,stdout
input = stdin.readline
# from math import gcd,ceil
# from collections import *
# from heapq import heapify,heappop,heappush
# from time import time
# from bisect import bisect, bisect_left

# for _ in range(int(input())):
	# n = int(input())
	
# ma,mi = map(int,input().split())
n,q = map(int,input().split())
# a = list(map(int,input().split()))
# s = list(input().rstrip('\n')
dp = [[0 for i in range(n)] for i in range(2)]

count = 0
for _ in range(q):
	a,b = map(int,input().split())
	if dp[a-1][b-1] != 1:
		dp[a-1][b-1] = 1
		if a != 2: # a = 1
			if dp[1][b-1] == 1:
				count += 1
			if b != n:
				if dp[1][b] == 1:
					count += 1
			if b != 1:
				if dp[1][b-2] == 1:
					count += 1
		elif a != 1:
			if dp[0][b-1] == 1:
				count += 1
			if b != n:
				if dp[0][b] == 1:
					count += 1
			if b != 1:
				if dp[0][b-2] == 1:
					count += 1
	elif dp[a-1][b-1] == 1:
		dp[a-1][b-1] = 0
		if a != 2: # a = 1
			if dp[1][b-1] == 1:
				count -= 1
			if b != n:
				if dp[1][b] == 1:
					count -= 1
			if b != 1:
				if dp[1][b-2] == 1:
					count -= 1
		elif a != 1:
			if dp[0][b-1] == 1:
				count -= 1
			if b != n:
				if dp[0][b] == 1:
					count -= 1
			if b != 1:
				if dp[0][b-2] == 1:
					count -= 1						
	if count == 0:
		print("YES")
	else:
		print("NO")									