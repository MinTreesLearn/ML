import sys
import threading
input=sys.stdin.readline
from collections import Counter,defaultdict,deque
from heapq import heappush,heappop,heapify
#threading.stack_size(10**8)
#sys.setrecursionlimit(10**6)

def ri():return int(input())
def rs():return input()
def rl():return list(map(int,input().split()))
def rls():return list(input().split())

def main():
	n=ri()
	a=rl()
	d=defaultdict(list)
	for l in range(n):
		cs=0
		for r in range(l,n):
			cs+=a[r]
			d[cs].append((l,r))
	res=[]
	for s in d:
		d[s].sort(key=lambda x:x[1])
		curr=[]
		prev=-1
		for r in d[s]:
			if r[0]>prev:
				prev=r[1]
				curr.append(r)
		if len(curr)>len(res):
			res=curr
	print(len(res))
	for l,r in res:
		print(l+1,r+1)
	pass

main()
#threading.Thread(target=main).start()
