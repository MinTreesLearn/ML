from heapq import heappush,heappop,_heapify_max,heapify
import operator as op
import sys
from bisect import bisect_left as b_l
from bisect import bisect_right as b_r
from collections import defaultdict, deque
from functools import reduce
from math import ceil, factorial, gcd, sqrt,log2,log

INT_MAX = sys.maxsize-1
INT_MIN = -sys.maxsize
mod=int(1e9)+7


def ncr(n,r):
	r=min(n,n-r)
	nmtr = reduce(op.mul,range(n,n-r,-1),1)
	dnmtr = reduce(op.mul,range(1,r+1),1)
	return nmtr//dnmtr


def fact(n):
	return factorial(n)







def myyy__answer():
	n,k=map(int,input().split())
	s=input()
	pre=[[0 for i in range(26)] for i in range(n+1)]

	for i in range(n):
		x=ord(s[i])-ord("a")
		for j in range(26):
			if(j==x):
				pre[i+1][j]+=pre[i][j]+1
			else:
				pre[i+1][j]=pre[i][j]

	ans=[0 for i in range(26)]

	q=list(map(int,input().split()))
	q.append(n)

	for i in q:
		for j in range(26):
			ans[j]+=pre[i][j]
	
	print(*ans)
	



	




		


	




	
	






	

	

	





	
	



			

		



	









	






	





		

	



	
	


	



	





	
			
		

	

	
	


		






	



	

	


	

	


	
	





if __name__ == "__main__":
	input = lambda: sys.stdin.readline().rstrip("\r\n").strip()

	for _ in range(int(input())):
		# print(myyy__answer())
		myyy__answer()
