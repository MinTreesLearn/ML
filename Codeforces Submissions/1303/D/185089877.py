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
	for _ in range(ri()):
		n,m=rl()
		a=sorted(rl())
		if sum(a)<n:print(-1);continue
		c=Counter(a)
		res=0
		i=0
		while i<64:
			if n&(1<<i):
				if c[1<<i]:
					c[1<<i]-=1
					c[1<<(i+1)]+=c[1<<i]//2
					i+=1
				else:
					j=i+1
					while not c[1<<j]:j+=1
					c[1<<j]-=1
					res+=j-i
					i=j
			else:
				c[1<<(i+1)]+=c[1<<i]//2
				i+=1
		print(res)
	pass

main()
#threading.Thread(target=main).start()
