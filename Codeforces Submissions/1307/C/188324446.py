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
s=str(input())
n=len(s)
b=set()
a={}
res=-float("inf")
for j in range(1,n):
	for i in range(26):
		a[chr(ord('a')+i)]=0
	c=1
	if s[j-1] in b:
		continue
	else:
		b.add(s[j-1])
	for i in range(j,n):
		a[s[i]]+=c
		if s[i]==s[j-1]:
			c+=1
	res=max(res,max(a.values()))
for i in range(26):
	a[chr(ord('a')+i)]=0
for i in s:
	a[i]+=1
res=max(res,max(a.values()))
print(res)





	