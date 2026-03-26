from sys import stdin
input=stdin.readline
class BIT():
	def __init__(self, n):
		self.n = n
		self.tree = [0] * (n + 1)

	def sum(self, i):
		ans = 0
		i += 1
		while i > 0:
			ans += self.tree[i]
			i -= (i & (-i))
		return ans

	def update(self, i, value):
		i += 1
		while i <= self.n:
			self.tree[i] += value
			i += (i & (-i))

from collections import  defaultdict
di=defaultdict(list)
n=int(input())
bt=BIT(n)
a=[*map(int,input().strip().split())]
for i in range(n):
	bt.update(i,a[i])
for i in range(n):
	for j in range(i+1):
		l=0
		if j!=0:
			l=bt.sum(j-1)
		r=bt.sum(i)
		s=r-l
		di[s].append((j,i))
# print(di[3])
ans=defaultdict(int)
ans=[]
for val in di:
	li=di[val]
	li.sort(key=lambda s:s[1])
	mxr=-1
	mx=[]
	cr=[]
	for l,r in li:
		if l>mxr:
			mxr=max(r,mxr)
			cr.append((l,r))
	mx=max(mx,cr,key=len)
	ans=max(mx,ans,key=len)
print(len(ans))
for l,r in ans:
	print(l+1,r+1)
