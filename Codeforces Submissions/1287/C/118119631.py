def gcd(a,b): return math.gcd(a,b)
def lcm(a,b): return ((a*b)//math.gcd(a,b))
def ncr(n,r): return math.comb(n,r)
def npr(n,r): return (math.factorial(n)//math.factorial(n-r))
def decimal_to_binary(n): return bin(n).replace("0b", "")
def binary_to_decimal(s): return int(s,2)

import sys, os.path
import math
from collections import defaultdict,deque

input = sys.stdin.readline

I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input1()))

mem1 = {}
def solve(i,prev,even,odd):
	if i>=len(p):
		return 0 
	if (i,prev,even,odd) in mem1:
		return mem1[(i,prev,even,odd)]
	if p[i]==0:
		if prev==1:
			op1 = 10**10
			op2 = 10**10
			if even>0:
				op1  = 1+solve(i+1,0,even-1,odd)
			if odd>0:
				op2  = solve(i+1,1,even,odd-1)
			mem1[(i,prev,even,odd)] = min(op1,op2)
			return mem1[(i,prev,even,odd)]
		else:
			op1 = 10**10
			op2 = 10**10
			if even>0:
				op1  = solve(i+1,0,even-1,odd)
			if odd>0:
				op2  = 1+solve(i+1,1,even,odd-1)
			mem1[(i,prev,even,odd)] = min(op1,op2)
			return mem1[(i,prev,even,odd)]
	else:
		op1 = 10**10
		op2 = 10**10
		if p[i]%2==0:
			if prev==1:
				op1 =  1+solve(i+1,0,even,odd)
			else:
				op1 =  solve(i+1,0,even,odd)
		else:
			if prev==1:
				op1 =  solve(i+1,1,even,odd)
			else:
				op1 =  1+solve(i+1,1,even,odd)
		mem1[(i,prev,even,odd)] = min(op1,op2)
		return mem1[(i,prev,even,odd)]


n,  = I()
p   = I()
count = [0]*102
for i in range(len(p)):
	count[p[i]] = 1
counte = 0
counto = 0
for i in range(1,n+1):
	if count[i]==0 and i%2==0:
		counte+=1
	if count[i]==0 and i%2!=0:
		counto+=1
if p[0]==0:
	op1 = 10**10
	op2 = 10**10
	if counte>0:
		# print('op1')
		# print(0,-1,counte-1,counto)
		op1  = solve(1,0,counte-1,counto)
	if counto>0:
		# print('op2')
		# print(0,-1,counte,counto-1)
		op2  = solve(1,1,counte,counto-1)
	print(min(op1,op2))
else:
	if p[0]%2==0:
		print(solve(1,0,counte,counto))
	else:
		print(solve(1,1,counte,counto))

