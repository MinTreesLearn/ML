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
	b=defaultdict(list)
	f=defaultdict(list)
	n,m=rl()
	for _ in range(m):
		u,v=rl()
		f[u].append(v)
		b[v].append(u)
	k=ri()
	p=rl()
	dis=[1<<33]*(n+1)
	q=deque([(p[-1],0)])
	dis[p[-1]]=0
	vis=set()
	while q:
		cn,cd=q.popleft()
		vis.add(cn)
		dis[cn]=min(dis[cn],cd)
		for nn in b[cn]:
			if nn not in vis:
				q.append((nn,cd+1))
				vis.add(nn)
	#print(dis)
	mn,mx=0,0
	for i in range(k-1):
		if dis[p[i+1]]>dis[p[i]]-1:
			mx+=1;mn+=1
		else:
			c=0
			for j in f[p[i]]:
				if dis[j]==dis[p[i]]-1:
					c+=1
			if 	c>1:
				mx+=1
	print(mn,mx)
	pass

main()
#threading.Thread(target=main).start()
