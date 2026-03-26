# 10:59-

import sys
input = lambda: sys.stdin.readline().strip()

from collections import Counter

N,M,K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

recs = set()
for i in range(1,int(K**0.5)+1):
	if K%i==0:
		recs.add((i,K//i))
		recs.add((K//i,i))

def get_segs(A):
	segs = [0]
	for a in A:
		if a==0:
			if segs[-1]>0:
				segs.append(0)
		else:
			segs[-1]+=1
	if segs[-1]==0:
		segs.pop()

	return Counter(segs)

def get_cnt(w,h):
	ans=0
	for w1,h1 in recs:
		if w1>w or h1>h:continue
		ans+=(w-w1+1)*(h-h1+1)
	return ans

AC,BC=get_segs(A),get_segs(B)

ans=0
for ak,av in AC.items():
	for bk,bv in BC.items():
		if ak*bk<K:continue
		ans+=get_cnt(ak,bk)*av*bv

print(ans)


