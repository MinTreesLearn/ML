import sys
import math
from collections import *
from functools import cmp_to_key
mod=998244353
def get_ints(): 
	return map(int, sys.stdin.readline().strip().split())

#test=int(input())
#while test:
#test-=1
n=int(input())
a=list(get_ints())
t=-float("inf")
f=[0 for i in range(n)]
for i in range(n):
	res={}
	s=0
	res[i]=a[i]
	s+=a[i]
	for j in range(i-1,-1,-1):
		if a[j]<=res[j+1]:
			res[j]=a[j]
		else:
			res[j]=res[j+1]
		s+=res[j]
	for j in range(i+1,n):
		if a[j]<=res[j-1]:
			res[j]=a[j]
		else:
			res[j]=res[j-1]
		s+=res[j]
	if s>t:
		t=s
		for k in res.keys():
			f[k]=res[k]
[print(i,end=' ') for i in f]
print()

	
